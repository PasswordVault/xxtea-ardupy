/**
 */
#include "xxtea-lib/src/xxtea-lib.h"

extern "C" {
    #include "py/mphal.h"
    #include "py/nlr.h"
    #include "py/objtype.h"
    #include "py/runtime.h"
    #include "shared-bindings/util.h"
}

#define xxtea_module (*(xxtea_c*)self->module)

extern "C" {
    void common_hal_xxtea_construct(abstract_module_t* self) {
        self->module = &xxtea;
    }
    void common_hal_xxtea_deinit(abstract_module_t* self) {
        // no op
    }
    bool common_hal_xxtea_set_key(abstract_module_t* self, char* password) {
        return ((xxtea_c*)self->module)->setKey(password);
    }
    char* common_hal_xxtea_encrypt(abstract_module_t* self, char* data) {
        return ((xxtea_c*)self->module)->encrypt(data);
    } 
    char* common_hal_xxtea_decrypt(abstract_module_t* self, char* data) {
        return ((xxtea_c*)self->module)->decrypt(data);
    } 
}
