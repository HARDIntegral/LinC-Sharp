#pragma pack(1)
typedef struct vars {
    int x;
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
MODULE_API void bridge_init();
#ifdef __cplusplus
}
#endif
