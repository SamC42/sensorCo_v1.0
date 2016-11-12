#include <bson.h>
#include <bcon.h>
#include <mongoc.h>
/*
MongoDB API

Commands:
1. Insert - A New Sensor
2. Delete
3. Update

*/

int insertSensor(char *senseid,char *val ){
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
                      "name", senseid,
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
/*
int main (int   argc,
      char *argv[])
{
	int one;
	one = "2";
	insert_mdb(one);
}
*/
// The Following Method gets the List of Sensors

int getCollSensors(){
   mongoc_client_t      *client;
   mongoc_collection_t  *collection;
   mongoc_cursor_t      *cursor;
   const bson_t         *doc;
   bson_t               *query;
   char                 *str;
   
   mongoc_init ();
   client = mongoc_client_new ("mongodb://127.0.0.1:3001");
   collection = mongoc_client_get_collection (client, "meteor", "sensors");
   query = bson_new();
   //Command to only get certain sensors
   //BSON_APPEND_UTF8(query, "name" ,"Name0");

   cursor = mongoc_collection_find (collection, MONGOC_QUERY_NONE,0,0,0, query,NULL,NULL);

   while (mongoc_cursor_next (cursor, &doc)){
    str = bson_as_json (doc, NULL);
    printf("%s\n",str);
    bson_free(str);
   }
   bson_destroy(query);
   mongoc_cursor_destroy(cursor);
   mongoc_collection_destroy(collection);
   mongoc_client_destroy(client);
   mongoc_cleanup();
   return 0;


}

int updateSensor(){
  mongoc_collection_t *collection;
  mongoc_client_t *client;
  bson_error_t error;
  bson_t *doc = NULL;
  bson_t *update = NULL;
  bson_t *query = NULL;

  mongoc_init ();
  client = mongoc_client_new ("mongodb://127.0.0.1:3001");
  collection = mongoc_client_get_collection (client, "meteor", "sensors");

  query = BCON_NEW("name", "Name0");
  update =BCON_NEW("$set","{","val", "2","}");

  if(!mongoc_collection_update(collection,MONGOC_UPDATE_NONE,query,update,NULL,&error)){
    fprintf(stderr, "%s\n", error.message);
    goto fail;
  }
  fail:
    if(doc)
      bson_destroy(doc);
    if(query)
      bson_destroy(query);
    if(update)
      bson_destroy(update);
    mongoc_collection_destroy(collection);
    mongoc_client_destroy(client);
    mongoc_cleanup();
    return 0;


}