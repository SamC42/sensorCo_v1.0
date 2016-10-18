/*
This is the header file for buff_read.c
*/

#ifndef buff_read_H_
#define buff_read_H_

#include "../sql/connect_sql.h"


int buff_read(int file_d, void *buf, int count_size);


#endif
