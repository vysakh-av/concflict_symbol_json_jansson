#include <jansson.h>
#include <stdlib.h>
#include <string.h>

int jansson_c_lib_init(const char *buffer)
{
    printf("[%s:%d] Enter: \n", __FUNCTION__, __LINE__);

    json_t *root;
    json_error_t error;


    printf("buffer = %s \n", buffer);
    root = json_loads(buffer, 0 , &error);
    if (root == NULL)
    {
        printf("[%s:%d] Failed to load json buffer \n", __FUNCTION__, __LINE__);
        return -1;
    }

    //char *s = json_dumps(root, 0);
    //printf("%s \n", s);
    json_t *schema = NULL;
    json_t *port = NULL;
    const char *schema_path;
    int server_port;

    schema = json_object_get(root, "name");

    if (schema == NULL)
    {
        printf("[%s:%d] Failed to get hal_schema_path \n", __FUNCTION__, __LINE__);
        return -1;
    }
    printf("%s \n", json_string_value(schema));
    schema_path = json_string_value(schema);

    port = json_object_get(root, "age");
    server_port = json_integer_value(port);

    printf("[%s:%d] name = %s \n", __FUNCTION__, __LINE__, schema_path);
    printf("[%s:%d] age = %d \n", __FUNCTION__, __LINE__, server_port);
    printf("[%s:%d] Exit: \n", __FUNCTION__, __LINE__);
    if (root)
        json_decref(root);
    return 0;
}
