/**
 */
#include "xxtea-lib/src/xxtea-lib.h"

extern "C" {
    bool ardupy_wrapper_xxtea_set_key(const char* key) {
        return xxtea.setKey(key);
    }
    const char* ardupy_wrapper_xxtea_encrypt(const char* data) {
        return xxtea.encrypt(data).c_str();
    }
    const char* ardupy_wrapper_xxtea_decrypt(const char* data) {
        return xxtea.decrypt(data).c_str();
    }
}