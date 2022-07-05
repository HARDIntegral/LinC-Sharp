#pragma pack(1)
typedef struct vars {
    int num_vars;
    void** vars;
} vars_t;
#pragma pack()

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#  ifdef MODULE_API_EXPORTS
#    define MODULE_API __declspec(dllexport)
#  else
#    define MODULE_API __declspec(dllimport)
#  endif
#else
#  define MODULE_API
#endif
MODULE_API vars_t* bridge_init();
MODULE_API void receive_data(void* data, int type);
MODULE_API void send_data(void* data, int type);
#ifdef __cplusplus
}
#endif
