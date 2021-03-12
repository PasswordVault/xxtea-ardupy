/**
 */
#include "py/mphal.h"
#include "py/nlr.h"
#include "py/objtype.h"
#include "py/runtime.h"
#include "py/obj.h"
#include "shared-bindings/util.h"

void common_hal_xxtea_construct(abstract_module_t* self);
void common_hal_xxtea_deinit(abstract_module_t* self);
bool common_hal_xxtea_set_key(abstract_module_t* self, char* password);
char* common_hal_xxtea_encrypt(abstract_module_t* self, char* data);
char* common_hal_xxtea_decrypt(abstract_module_t* self, char* data);

m_generic_make(xxtea_module) {
    abstract_module_t* self = new_abstruct_module(type);
    mp_arg_check_num(n_args, n_kw, 0, 0, false);
    common_hal_xxtea_construct(self);
    return self;
}

void 
xxtea_obj_attr(mp_obj_t self_in, qstr attr, mp_obj_t* dest) {
    return;
}

mp_obj_t 
xxtea_setKey(size_t n_args, const mp_obj_t* pos_args, mp_map_t* kw_args) {
    abstract_module_t* self = (abstract_module_t*) pos_args[0];
    char* password = mp_obj_str(pos_args[1]);
    bool success = common_hal_xxtea_set_key(self, password);
    return mp_obj_new_bool(success);
}
MP_DEFINE_CONST_FUN_OBJ_KW(xxtea_setKey_obj, 1, xxteam_setKey);

mp_obj_t 
xxtea_encrypt(size_t n_args, const mp_obj_t* pos_args, mp_map_t* kw_args) {
    abstract_module_t* self = (abstract_module_t*) pos_args[0];
    char* data = mp_obj_str(pos_args[1]);
    char* result = common_hal_xxtea_encrypt(self, data);
    return mp_obj_new_str(result);
}
MP_DEFINE_CONST_FUN_OBJ_KW(xxtea_encrypt_obj, 1, xxteam_encrypt);

mp_obj_t 
xxtea_decrypt(size_t n_args, const mp_obj_t* pos_args, mp_map_t* kw_args) {
    abstract_module_t* self = (abstract_module_t*) pos_args[0];
    char* data = mp_obj_str(pos_args[1]);
    char* result = common_hal_xxtea_decrypt(self, data);
    return mp_obj_new_str(result);
}
MP_DEFINE_CONST_FUN_OBJ_KW(xxtea_decrypt_obj, 1, xxteam_decrypt);

const mp_rom_map_elem_t xxtea_locals_dict_table[] = {
    // instance methods
    { MP_ROM_QSTR(MP_QSTR_deinit),    MP_ROM_PTR(&xxtea_deinit_obj) },
    { MP_ROM_QSTR(MP_QSTR___enter__), MP_ROM_PTR(&default___enter___obj) },
    { MP_ROM_QSTR(MP_QSTR___exit__),  MP_ROM_PTR(&xxtea_obj___exit___obj) },
    { MP_ROM_QSTR(MP_QSTR_setKey), MP_ROM_PTR(&xxtea_setKey_obj)},
    { MP_ROM_QSTR(MP_QSTR_encrypt), MP_ROM_PTR(&xxtea_encrypt_obj)},
    { MP_ROM_QSTR(MP_QSTR_decrypt), MP_ROM_PTR(&xxtea_decrypt_obj)},
};
 
MP_DEFINE_CONST_DICT(xxtea_locals_dict, xxtea_locals_dict_table);

const mp_obj_type_t xxtea_type = {
    {&mp_type_type},
    .name = MP_QSTR_xxtea,
    .make_new = xxtea_make_new,
    .locals_dict = (mp_obj_t)&xxtea_locals_dict,
    .attr = xxtea_obj_attr,
};

