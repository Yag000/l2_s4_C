#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

struct array
{
    int *content;
    size_t capacity;
    size_t size;
};
typedef struct array array;

array *array_init(size_t capacity);
void array_destroy(array *pa);

int array_get(array *pa, size_t index);
void array_set(array *pa, size_t index, int value);
bool array_append(array *pa, int value);

void array_print(array *pa);

int *array_search(array *pa, int value);
array *array_init_from(int *data, size_t length, size_t capacity);
void array_remove(array *pa, size_t index);
void array_insert(array *pa, size_t index, int value);

void test_array_get();
void test_array_set();
void test_array_append();
void test_array_search();
void test_array_init_from();
void test_array_remove();
void test_array_insert();

int main()
{
    test_array_get();
    test_array_set();
    test_array_append();
    test_array_search();
    test_array_init_from();
    test_array_remove();
    test_array_insert();
    return EXIT_SUCCESS;
}

array *array_init(size_t capacity)
{
    array *a = malloc(sizeof(array));
    if (a == NULL)
    {
        return NULL;
    }

    a->content = malloc(capacity * sizeof(int));
    if (a->content == NULL)
    {
        free(a);
        return NULL;
    }
    a->capacity = capacity;
    a->size = 0;
    return a;
}

void array_destroy(array *pa)
{
    free(pa->content);
    free(pa);
}

int array_get(array *pa, size_t index)
{
    assert(index < pa->size);
    return *(pa->content + index);
}

void array_set(array *pa, size_t index, int value)
{
    assert(index < pa->size);
    *(pa->content + index) = value;
}

bool array_append(array *pa, int value)
{
    if (pa->size == pa->capacity)
    {
        return false;
    }

    *(pa->content + pa->size) = value;
    pa->size++;
    return true;
}

void array_print(array *pa)
{
    for (int *ptr = pa->content; ptr < pa->content + pa->size; ptr++)
    {
        printf("%d ", *ptr);
    }
    puts("");
}

int *array_search(array *pa, int value)
{
    for (int *ptr = pa->content; ptr < pa->content + pa->size; ptr++)
    {
        if (*ptr == value)
        {
            return ptr;
        }
    }

    return NULL;
}

array *array_init_from(int *data, size_t length, size_t capacity)
{
    assert(length <= capacity);

    array *a = array_init(capacity);
    if (a == NULL)
    {
        return NULL;
    }

    for (int *ptr = data; ptr < data + length; ptr++)
    {
        array_append(a, *ptr);
    }

    return a;
}

void array_remove(array *pa, size_t index)
{
    assert(index < pa->size);

    for (int *ptr = pa->content + index; ptr < pa->content + pa->size - 1; ptr++)
    {
        *ptr = *(ptr + 1);
    }

    pa->size--;
}

void realloc_array(array *pa)
{
    int *new_content = realloc(pa->content, pa->capacity * 2 * sizeof(int));
    if (new_content == NULL)
    {
        return;
    }

    pa->content = new_content;
    pa->capacity *= 2;
}

void array_insert(array *pa, size_t index, int value)
{

    assert(index <= pa->size);

    if (pa->size == pa->capacity)
    {
        realloc_array(pa);
    }

    if (index == pa->size)
    {
        array_append(pa, value);
        return;
    }

    for (int *ptr = pa->content + pa->size; ptr > pa->content + index; ptr--)
    {
        *ptr = *(ptr - 1);
    }

    *(pa->content + index) = value;
    pa->size++;
}

void test_array_get()
{
    puts("---------- Test array_get ----------");
    puts("Expected: 1 2 3 4 5 6 7 8 9 10");
    printf("Actual: ");
    array *a = array_init(10);
    array_append(a, 1);
    array_append(a, 2);
    array_append(a, 3);
    array_append(a, 4);
    array_append(a, 5);
    array_append(a, 6);
    array_append(a, 7);
    array_append(a, 8);
    array_append(a, 9);
    array_append(a, 10);
    for (size_t i = 0; i < 10; i++)
    {
        printf("%d ", array_get(a, i));
    }
    puts("\n----------- End test array_get -----------\n");
    array_destroy(a);
}

void test_array_set()
{
    puts("---------- Test array_set ----------");
    puts("Expected: 11 12 13 14 15 16 17 18 19 20");
    printf("Actual: ");
    array *a = array_init(10);
    array_append(a, 1);
    array_append(a, 2);
    array_append(a, 3);
    array_append(a, 4);
    array_append(a, 5);
    array_append(a, 6);
    array_append(a, 7);
    array_append(a, 8);
    array_append(a, 9);
    array_append(a, 10);
    for (size_t i = 0; i < 10; i++)
    {
        array_set(a, i, i + 11);
    }
    array_print(a);
    array_destroy(a);

    puts("----------- End test array_set -----------\n");
}

void test_array_append()
{
    puts("---------- Test array_append ----------");
    puts("Expected: 1 2 3 4 5 6 7 8 9 10");
    printf("Actual: ");
    array *a = array_init(10);
    array_append(a, 1);
    array_append(a, 2);
    array_append(a, 3);
    array_append(a, 4);
    array_append(a, 5);
    array_append(a, 6);
    array_append(a, 7);
    array_append(a, 8);
    array_append(a, 9);
    array_append(a, 10);
    array_print(a);
    array_destroy(a);

    puts("----------- End test array_append -----------\n");
}

void test_array_search()
{
    puts("---------- Test array_search ----------");
    puts("Expected: 1 2 3 4 5 6 7 8 9 10");
    printf("Actual: ");
    array *a1 = array_init(10);
    array_append(a1, 10);
    array_append(a1, 9);
    array_append(a1, 8);
    array_append(a1, 7);
    array_append(a1, 6);
    array_append(a1, 5);
    array_append(a1, 4);
    array_append(a1, 3);
    array_append(a1, 2);
    array_append(a1, 1);
    for (size_t i = 0; i < 10; i++)
    {
        printf("%d ", *array_search(a1, i + 1));
    }
    puts("");

    puts("\n### Test case: Element not found");
    puts("Expected: (nil)");
    printf("Actual: %p \n", array_search(a1, 11));
    array_destroy(a1);

    puts("\n### Test case: FInding the first instance");
    puts("Expected: true false false");
    array *a2 = array_init(5);
    array_append(a1, 2);
    array_append(a1, 1);
    array_append(a1, 2);
    array_append(a1, 1);
    array_append(a1, 1);
    printf("%s ", array_search(a2, 1) == a2->content + 1 ? "true" : "false");
    printf("%s ", array_search(a2, 1) == a2->content + 3 ? "true" : "false");
    printf("%s ", array_search(a2, 1) == a2->content + 4 ? "true" : "false");

    puts("\n----------- End test array_search -----------\n");
}

void test_array_init_from()
{
    puts("---------- Test array_init_from ----------");
    puts("Expected: 1 2 3 4 5 6 7 8 9 10");
    printf("Actual: ");
    int data[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    array *a = array_init_from(data, 10, 10);
    array_print(a);
    array_destroy(a);

    puts("----------- End test array_init_from -----------\n");
}

void test_array_remove()
{
    puts("---------- Test array_remove ----------");
    puts("### Test case: Removing first element");
    puts("Expected: 2 3 4 5 6 7 8 9 10");
    printf("Actual: ");
    int data[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    array *a = array_init_from(data, 10, 10);
    array_remove(a, 0);
    array_print(a);

    puts("\n### Test case: Removing last element");
    puts("Expected: 2 3 4 5 6 7 8 9");
    printf("Actual: ");
    array_remove(a, 8);
    array_print(a);

    puts("\n### Test case: Removing middle element");
    puts("Expected: 2 3 4 6 7 8 9");
    printf("Actual: ");
    array_remove(a, 3);
    array_print(a);
    array_destroy(a);

    puts("----------- End test array_remove -----------\n");
}

void test_array_insert()
{

    puts("---------- Test array_insert ----------");
    puts("### Test case: Adding an element at the end and at full capacity");
    puts("Expected: 1 2 3 4 5 6 7 8 9 10 11\nSize: 11\nCapacity: 20");
    printf("Actual: ");
    int data[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    array *a = array_init_from(data, 10, 10);
    array_insert(a, 10, 11);
    array_print(a);
    printf("Size: %zu \n", a->size);
    printf("Capacity: %zu \n", a->capacity);

    puts("\n### Test case: Adding an element at the beginning");
    puts("Expected: 0 1 2 3 4 5 6 7 8 9 10 11\nSize: 12\nCapacity: 20");
    printf("Actual: ");
    array_insert(a, 0, 0);
    array_print(a);
    printf("Size: %zu \n", a->size);
    printf("Capacity: %zu \n", a->capacity);

    puts("\n### Test case: Adding an element at the second to last index");
    puts("Expected: 0 1 2 3 4 5 6 7 8 9 10 200 11\nSize: 13\nCapacity: 20");
    printf("Actual: ");
    array_insert(a, 11, 200);
    array_print(a);
    printf("Size: %zu \n", a->size);
    printf("Capacity: %zu \n", a->capacity);

    puts("\n### Test case: Adding an element at the middle");
    puts("Expected: 0 1 2 3 4 5 300 6 7 8 9 10 200 11\nSize: 14\nCapacity: 20");
    printf("Actual: ");
    array_insert(a, 6, 300);
    array_print(a);
    printf("Size: %zu \n", a->size);
    printf("Capacity: %zu \n", a->capacity);

    puts("----------- End test array_insert -----------\n");
}