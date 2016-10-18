#include <bson.h>
#include <bcon.h>
#include <mongoc.h>

int main (int   argc,
      char *argv[])
{
   mongoc_client_t      *client;
   mongoc_database_t    *database;
   mongoc_collection_t  *collection;
   bson_t               *command,
                         reply,
                         *insert;
   bson_error_t          error;
   char                 *str;
   bool                  retval;

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
   //database = mongoc_client_get_database (client, "meteor");
   collection = mongoc_client_get_collection (client, "meteor", "sensors");

   /*
    * Do work. This example pings the database, prints the result as JSON and
    * performs an insert
    */
   command = BCON_NEW ("ping", BCON_INT32 (1));

   retval = mongoc_client_command_simple (client, "admin", command, NULL, &reply, &error);

   if (!retval) {
      fprintf (stderr, "%s\n", error.message);
      return EXIT_FAILURE;
   }

   str = bson_as_json (&reply, NULL);
   fprintf (stdout, "%s\n", str);

   insert = BCON_NEW (
                      "name", BCON_UTF8 ("Sensor"),
                      "val", "3");

   if (!mongoc_collection_insert (collection, MONGOC_INSERT_NONE, insert, NULL, &error)) {
      fprintf (stderr, "%s\n", error.message);
   }

   bson_destroy (insert);
   bson_destroy (&reply);
   bson_destroy (command);
   bson_free (str);

   /*
    * Release our handles and clean up libmongoc
    */
   mongoc_collection_destroy (collection);
   mongoc_database_destroy (database);
   mongoc_client_destroy (client);
   mongoc_cleanup ();

   return 0;
}