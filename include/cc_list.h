#ifndef __CC_LIST_H__
#define __CC_LIST_H__


typedef struct cc_list{
	int value;
	struct cc_list* nextElem;
}cc_list_t;

cc_list_t *list_dimensions;

void initializeList(cc_list_t *list);
void listAppendElem(cc_list_t* list, int newValue);
void listRemoveLastElem(cc_list_t* list);
void deleteList(cc_list_t* list);

#endif
