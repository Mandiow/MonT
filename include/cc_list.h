#ifndef __CC_LIST_H__
#define __CC_LIST_H__


typedef struct cc_list{
	int value;
	int dimensions;
	struct cc_list* nextElem;
}cc_list_t;

cc_list_t* list_dimensions;

void initializeList(cc_list_t **list);
void listAppendElem(cc_list_t **list, int newValue);
cc_list_t* listRemoveLastElem(cc_list_t *list);
void listCopyAppendElem(cc_list_t **list, int newValue);
void deleteList(cc_list_t **list);

#endif
