#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <json-c/json.h>
#include "json_c_lib.h"

int json_c_lib_init (char *buffer)
{
    printf("[%s:%d] Enter: \n", __FUNCTION__, __LINE__);

    json_object *jmsg = NULL;
    jmsg = json_tokener_parse(buffer);
    if (NULL == jmsg)
    {
        printf("[%s:%d] Failed to convert buffer to jsom message \n", __FUNCTION__, __LINE__);
        return -1;
    }

    json_object *schema = NULL;
    json_object *port = NULL;
    char schema_path[246] = {'\0'};
    int server_port;
    json_object_object_get_ex(jmsg, "name", &schema);
    json_object_object_get_ex(jmsg, "age", &port);
    strcpy(schema_path, json_object_get_string(schema));
    server_port = json_object_get_int(port);
    printf("[%s:%d] name = %s \n", __FUNCTION__, __LINE__, schema_path);
    printf("[%s:%d] age = %d \n", __FUNCTION__, __LINE__, server_port);
    printf("[%s:%d] Exit: \n", __FUNCTION__, __LINE__);
    return 0;
}