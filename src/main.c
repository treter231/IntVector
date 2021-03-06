#include <stdio.h>
#include "IntVector.h"

void printv(IntVector *v) {
	for(int i = 0; i < v->size; i++) {
		printf("%d ", v->data[i]);
	}
	printf("\n");
}

//Выводим ёмкость и размер
void size_capacity(IntVector *v) {
	printf("Size = %zu\n", int_vector_get_size(v));
	printf("Capacity = %zu\n\n", int_vector_get_capacity(v));
printf("---------------------------------------\n");
}

int main(){
//Выделяем размер массива
	IntVector *v = int_vector_new(3);
	size_capacity(v);

//Копируем массив
       	IntVector *c = int_vector_copy(v);
	size_capacity(c);

//Освобождаем место в памяти
	int_vector_free(c);

//
	//int_vector_get_item
	printf("Get item: %d\n", int_vector_get_item(v, 0));

//Присваивает элементу под номером index значение item
	//int_vector_set_item
	int_vector_set_item(v, 0, 5);
	printv(v);
	size_capacity(v);
	int_vector_set_item(v, 1, 6);
	printv(v);
	size_capacity(v);

//Добавление элемента в конец массива
	//int_vector_push_back
	if (int_vector_push_back(v, 7) == 0) {
			printf("Элемент успешно добавлен\n");
	}
	else {
		printf("Error\n");
	}
	printv(v);
	size_capacity(v);
//Удаление последнего элемента
	//int_vector_pop_back
	int_vector_pop_back(v);
	printv(v);
	size_capacity(v);

//Уменьшение ёмкости массива до его размера
	//int_vector_shrink_to_fit
	if (int_vector_shrink_to_fit(v) == -1) {
		printf("Error\n");
	}
	else {
		printf("Успешное изменение емкости\n");
	}
	size_capacity(v);
	printv(v);

//Изменение размера массива
	//int_vector_resize
	if (int_vector_resize(v, 3) == -1) {
		printf("Ошибка изменения размера массива\n");
	}
	else {
		printf("Успешное изменение размера массива\n");
	}
	size_capacity(v);
	printv(v);

//Изменение емкости массива (capasity)
	//int_vector_reserve
	if (int_vector_reserve(v, 9) == -1) {
		printf("Ошибка в увеличении емкости\n");
	}
	else {
		printf("Успешное увеличение емкости\n");
	}
	size_capacity(v);
	printv(v);

//Добавляет элемент в конец массива
	//int_vector_push_back
	if (int_vector_push_back(v, 7) == 0) { 
			printf("Элемент успешно добавлен\n");
	}
	else {
		printf("Error\n");
	}
	printv(v);
	size_capacity(v);
	int_vector_free(v);
	return 0;
}
