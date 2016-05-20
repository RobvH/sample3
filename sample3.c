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

#ifdef COMPILE_DL_SAMPLE3
ZEND_GET_MODULE(sample3)
#endif

#define PHP_SAMPLE3_SC_NAME "Sample3_SecondClass"

static const zend_function_entry php_sample3_sc_methods[] = {
	PHP_ME(Sample3_SecondClass, helloWorld, NULL, ZEND_ACC_PUBLIC)
	PHP_MALIAS(Sample3_SecondClass, sayHi, helloWorld, NULL, ZEND_ACC_PUBLIC)
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