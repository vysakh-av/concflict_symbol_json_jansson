#include <stdio.h>
#include <stdlib.h>
#include "json_c_lib.h"
#include "jansson_c_lib.h"
#include <json-c/json.h>
#define JSON_EXAMPLE_FILE "myFile.json"
#ifdef _JSONC_ENABLED
static void json_c_sample_call(const char * buffer)
{
    printf("[%s:%d] Enter  \n", __FUNCTION__, __LINE__);
    /* json_c call. */
    int rc;
    json_object *jmsg = NULL;
    jmsg = json_tokener_parse(buffer);
    if (NULL == jmsg)
    {
        printf("[%s:%d] Failed to convert buffer to jsom message \n", __FUNCTION__, __LINE__);
        return;
    }
    else
    {
        printf("[%s:%d]  json-c parsing is successful \n", __FUNCTION__, __LINE__);
    }
    printf("[%s:%d] Exit  \n", __FUNCTION__, __LINE__);

}
#endif
int main()
{
    FILE *fp = NULL;
    int rc;
    fp = fopen(JSON_EXAMPLE_FILE, "r");
    if (fp == NULL)
    {
        printf("[%s:%d] Empty file \n", __FUNCTION__, __LINE__);
        return -1;
    }

    char buffer[4096] = {'\0'};
    fread(buffer, sizeof(buffer), 1, fp);
    printf("[%s:%d] Buffer = %s \n", __FUNCTION__, __LINE__, buffer);
    fclose(fp);

#ifdef _JSONC_ENABLED
    json_c_sample_call(buffer);

    rc = json_c_lib_init(buffer);
    if (rc == 0)
    {
        printf("[%s:%d] json_c_lib_init() call successul  \n", __FUNCTION__, __LINE__);
    }
    else
    {
        printf("[%s:%d] json_c_lib_init() call successul  \n", __FUNCTION__, __LINE__);
    }
#endif

#ifdef _JANSSON_ENABLED
    rc = jansson_c_lib_init(buffer);
    if (rc == 0)
    {
        printf("[%s:%d] jansson_c_lib_init() call successul  \n", __FUNCTION__, __LINE__);
    }
    else
    {
        printf("[%s:%d] jansson_c_lib_init() call successul  \n", __FUNCTION__, __LINE__);
    }
#endif

    return 0;
}