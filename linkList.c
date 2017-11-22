#include "linkList.h"
#include <stdlib.h>
#include <stdio.h>

int add_to_list(linked_list *ll, char *s){
	linked_list *newlist=ll;
	int t = 0;
	while(newlist->next != NULL){
		newlist = newlist->next;
		t++;
	}
	t++;
	newlist->next = (linked_list* )malloc(sizeof(struct linked_list));
	newlist->next->data = s;
	newlist->next->next = NULL;
	newlist->next->index = t;
	newlist->next->prev = newlist;
	
	return t;

}
int display_item(linked_list *ll){
	if(ll->data == NULL){
		return -1;
	}
	else{
		// 0=OK
		printf("%s\n",ll->data);
		return 0;
	}
}
int display_list(linked_list *ll){
	linked_list *currlist=ll;
	int t = 0;
	while(currlist->next != NULL){
		currlist = currlist->next;
		printf("%s\n",currlist->data);
		t++;
	}
	return t;
}
/*
linked_list * search_from_list(linked_list *ll, char *s){
	linked_list *currlist=ll;
	while(currlist->next != NULL){
		currlist = currlist->next;
		if(currlist->data == s){
			return currlist;
		}
	}
	return 0;
}
*/
int delete_from_list(linked_list *ll, int index){
	linked_list *currlist = ll;
	linked_list *templist = NULL;
	int t = 0;
	if(index <= 0){
		return -1;
	}
    for (t = 0; t < index-1; t++){
        if (currlist->next == NULL){
			if(currlist->index == index-1){
				free(currlist);
				ll->next = NULL;
				return 0;
			}
            return -1;
        }
        currlist = currlist->next;
    }
	templist = currlist->next;
	currlist->next = templist->next;
	free(templist);
	
	currlist = ll;
	t=0;
	while(currlist->next != NULL){
		currlist = currlist->next;
		t++;
	}
	return t;
}

int empty_list(linked_list *ll){
	
    if (ll->next == NULL) {
        free(ll);
        return 0;
    }
	linked_list *currlist = ll;
    while (currlist->next->next != NULL) {
        currlist = currlist->next;
    }

    free(currlist->next);
    currlist->next = NULL;
    return 0;

}

int linkedlist_status(linked_list *ll){
	linked_list *currlist=ll;
	int t = 0;
	if(currlist == NULL){
		return -1;
	}
	while(currlist->next != NULL){
		currlist = currlist->next;
		printf("%s\n",currlist->data);
		t++;
	}
	return t;
}