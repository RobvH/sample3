#include "php_sample3.h"

static zend_function_entry php_sample3_functions[] = {
	{ NULL, NULL, NULL }
};

zend_module_entry sample3_module_entry = {
	STANDARD_MODULE_HEADER,
	PHP_SAMPLE3_EXTNAME,
	php_sample3_functions,
	PHP_MINIT(sample3),
	NULL, 					/* MSHUTDOWN */
	NULL,					/* RINIT */
	NULL,					/* RSHUTDOWN */
	NULL, 					/* MINFO */
	PHP_SAMPLE3_EXTVER,
	STANDARD_MODULE_PROPERTIES
};

PHP_METHOD(Sample3_SecondClass, helloWorld)
{
	php_printf("Hello World\n");
}

PHP_METHOD(Sample3_SecondClass, __construct)
{
	char *name = NULL;
	int name_len;
	sample3_SecondClass_object *obj;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|s", &name, &name_len) == FAILURE)  return;

	obj = (sample3_SecondClass_object *)zend_object_store_get_object(getThis() TSRMLS_CC);
}

#ifdef COMPILE_DL_SAMPLE3
ZEND_GET_MODULE(sample3)
#endif

#define PHP_SAMPLE3_SC_NAME "Sample3_SecondClass"

/* Generic arg-info structures for 1 and 2 parameter methods */

ZEND_BEGIN_ARG_INFO_EX(php_sample3_one_arg, 0, 0, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(php_sample3_two_args, 0, 0, 2)
ZEND_END_ARG_INFO()

static const zend_function_entry php_sample3_sc_methods[] = {
	PHP_ME(Sample3_SecondClass, helloWorld, NULL, ZEND_ACC_PUBLIC)
	PHP_MALIAS(Sample3_SecondClass, sayHi, helloWorld, NULL, ZEND_ACC_PUBLIC)

	/* Built in magic methods */
	PHP_ME(Sample3_SecondClass, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) /*
	PHP_ME(Sample3_SecondClass, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_ME(Sample3_SecondClass, __clone, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CLONE)
	PHP_ME(Sample3_SecondClass, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Sample3_SecondClass, __get, php_sample3_one_arg, ZEND_ACC_PUBLIC)
	PHP_ME(Sample3_SecondClass, __set, php_sample3_two_args, ZEND_ACC_PUBLIC)
	PHP_ME(Sample3_SecondClass, __call, php_sample3_two_args, ZEND_ACC_PUBLIC)
	PHP_ME(Sample3_SecondClass, __isset, php_sample3_one_arg, ZEND_ACC_PUBLIC)
	PHP_ME(Sample3_SecondClass, __unset, php_sample3_one_arg, ZEND_ACC_PUBLIC) */
	{ NULL, NULL, NULL }
};

zend_class_entry *php_sample3_sc_entry;

PHP_MINIT_FUNCTION(sample3)
{
	zend_class_entry ce;

	INIT_CLASS_ENTRY(ce, PHP_SAMPLE3_SC_NAME, php_sample3_sc_methods);
	php_sample3_sc_entry = zend_register_internal_class(&ce TSRMLS_CC);

	return SUCCESS;
}