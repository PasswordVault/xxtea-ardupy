/**
 */
#include "py/obj.h"
#include "py/runtime.h"

#include "xxtea-lib/src/xxtea-lib.h"

STATIC mp_obj_t xxtea_set_key(mp_obj_t key_obj) {
    char* key = mp_obj_get_str(key_obj);
    return mp_obj_new_bool(xxtea.setKey(key));
}
STATIC MP_DEFINE_CONST_FUN_OBJ_1(xxtea_set_key_obj, xxtea_set_key);

STATIC mp_obj_t xxtea_encrypt(mp_obj_t data_obj) {
    char* data = mp_obj_get_str(data_obj);
    char* result = xxtea.encrypt(data).c_str();
    return mp_obj_new_str(result, strlen(result));
}
STATIC MP_DEFINE_CONST_FUN_OBJ_1(xxtea_encrypt_obj, xxtea_encrypt);

STATIC mp_obj_t xxtea_decrypt(mp_obj_t data_obj) {
    char* data = mp_obj_get_str(data_obj);
    char* result = xxtea.decrypt(data).c_str();
    return mp_obj_new_str(result, strlen(result));
}
STATIC MP_DEFINE_CONST_FUN_OBJ_1(xxtea_decrypt_obj, xxtea_decrypt);

STATIC const mp_rom_map_elem_t xxtea_module_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_xxtea) },
    { MP_ROM_QSTR(MP_QSTR_set_key), MP_ROM_PTR(&xxtea_set_key_obj) },
    { MP_ROM_QSTR(MP_QSTR_encrypt), MP_ROM_PTR(&xxtea_encrypt_obj) },
    { MP_ROM_QSTR(MP_QSTR_decrypt), MP_ROM_PTR(&xxtea_decrypt_obj) },
};
STATIC MP_DEFINE_CONST_DICT(xxtea_module_globals, xxtea_module_globals_table);

const mp_obj_module_t xxtea_user_cmodule = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t*)&xxtea_module_globals,
};

MP_REGISTER_MODULE(MP_QSTR_xxtea, xxtea_user_cmodule, MODULE_SIMPLEFUNCTION_ENABLED);
