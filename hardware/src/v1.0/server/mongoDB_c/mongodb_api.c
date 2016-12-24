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

int insertSensor(char *sense_id,char *sense_val, char *cont_instr, char *cont_data, char *sense_instr, char *sense_data)
 {
   mongoc_client_t      *client;
   mongoc_collection_t  *collection;
   bson_t               *insert;
   bson_error_t          error;
   char                 *str;

   mongoc_init ();
   client = mongoc_client_new ("mongodb://127.0.0.1:3001");
   collection = mongoc_client_get_collection (client, "meteor", "sensors");

   insert = BCON_NEW ("sense_id", sense_id,"sense_val", sense_val, "cont_instr",cont_instr,"cont_data",cont_data,"sense_instr",sense_instr,"sense_data",sense_data);

   if (!mongoc_collection_insert (collection, MONGOC_INSERT_NONE, insert, NULL, &error)) {
      fprintf (stderr, "%s\n", error.message);
   }
	bson_destroy (insert);
  mongoc_collection_destroy (collection);
  mongoc_client_destroy (client);
  mongoc_cleanup ();
  return 1;
}

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

int updateSensor(char *sense_id,char *val){
  mongoc_collection_t *collection;
  mongoc_client_t *client;
  bson_error_t error;
  bson_t *doc = NULL;
  bson_t *update = NULL;
  bson_t *query = NULL;
  
  mongoc_init ();
  client = mongoc_client_new ("mongodb://127.0.0.1:3001");
  collection = mongoc_client_get_collection (client, "meteor", "sensors");

  query = BCON_NEW("sense_id", sense_id);
  update =BCON_NEW("$set","{","sense_val", val,"}");

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