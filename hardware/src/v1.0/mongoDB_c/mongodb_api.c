#include <bson.h>
#include <bcon.h>
#include <mongoc.h>
/*
MongoDB API

Commands:
1. Insert
2. Delete
3. Update

*/

int insert_mdb(int val){
   mongoc_client_t      *client;
   mongoc_collection_t  *collection;
   bson_t               *insert;
   bson_error_t          error;
   char                 *str;
   /*
    * Required to initialize libmongoc's internals
    */
   mongoc_init ();
   /*
    * Create a new client instance
    */
   client = mongoc_client_new ("mongodb://127.0.0.1:3001");
   /*
    * Get a handle on the database "db_name" and collection "coll_name"
    */
   collection = mongoc_client_get_collection (client, "meteor", "sensors");

   insert = BCON_NEW (
                      "name", BCON_UTF8 ("Sensor"),
                      "val", val
                      );

   if (!mongoc_collection_insert (collection, MONGOC_INSERT_NONE, insert, NULL, &error)) {
      fprintf (stderr, "%s\n", error.message);
   }
	bson_destroy (insert);
   /*
    * Release our handles and clean up libmongoc
    */
   mongoc_collection_destroy (collection);
   mongoc_client_destroy (client);
   mongoc_cleanup ();
   return 1;
}

int delete_mdb(){

}

int update_mdb(){


}
/*
int main (int   argc,
      char *argv[])
{
	int one;
	one = "2";
	insert_mdb(one);
}
*/