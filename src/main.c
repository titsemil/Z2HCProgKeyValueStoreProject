#include <stdio.h>
#include <kv.h>
#include <assert.h>

int main()
{
	kv_t *table = kv_init(1024);
	printf("%p\n", table);
	printf("%ld\n", table->capacity);

	kv_put(table, "hehe", "haha");
	kv_put(table, "hehe", "hoho");
	kv_put(table, "lala", "yolo");

	for (int i = 0; i < table->capacity; i++)
	{
		if (table->entries[i].key)
		{
			printf("[%d] %s: %s\n",
				i,
				table->entries[i].key,
				table->entries[i].value);
		}
	}

	char *val1 = kv_get(table, "hehe");
	char *val2 = kv_get(table, "lala");
	char *val3 = kv_get(table, "this_is_not_here");

	printf("%s %s %s\n", val1, val2, val3);

	kv_delete(table, "hehe");
	val1 = NULL;
	val1 = kv_get(table, "hehe");

	printf("%s %s %s\n", val1, val2, val3);
}