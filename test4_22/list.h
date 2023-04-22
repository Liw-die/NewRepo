/* SPDX-License-Identifier: GPL-2.0 */
#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
#include <stddef.h>

/* Are two types/vars the same type (ignoring qualifiers)? */
/*两个类型/var是否为同一类型（忽略限定符）*/

#define __same_type(a, b) __builtin_types_compatible_p(typeof(a), typeof(b))

/**
 * container_of - cast a member of a structure out to the containing structure
 * @ptr:	the pointer to the member.
 * @type:	the type of the container struct this is embedded in.
 * @member:	the name of the member within the struct.
 *
 */
 /**
*container_of-将结构的成员强制转换为包含结构
*@ptr：指向成员的指针。
*@type：它所嵌入的容器结构的类型。
*@member：结构中成员的名称。
*
*/
#define container_of(ptr, type, member) ({				\
	void *__mptr = (void *)(ptr);					\
	_Static_assert(__same_type(*(ptr), ((type *)0)->member) ||	\
		      __same_type(*(ptr), void),			\
		      "pointer type mismatch in container_of()");	\
	((type *)(__mptr - offsetof(type, member))); })

#define LIST_POISON1  ((void *) 0x100)
#define LIST_POISON2  ((void *) 0x122)

/*
 * Circular doubly linked list implementation.
 *
 * Some of the internal functions ("__xxx") are useful when
 * manipulating whole lists rather than single entries, as
 * sometimes we already know the next/prev entries and we can
 * generate better code by using them directly rather than
 * using the generic single-entry routines.
 */
 /*
*循环双链表实现。
*
*某些内部函数（“__xxx”）在以下情况下很有用
*操作整个列表而不是单个条目
*有时我们已经知道下一个/上一个条目，我们可以
*直接使用它们生成更好的代码，而不是
*使用通用的单条目例程。
*/

struct list_head {
	struct list_head *next, *prev;
};

#define LIST_HEAD_INIT(name) { &(name), &(name) }

#define LIST_HEAD(name) \
	struct list_head name = LIST_HEAD_INIT(name)

/**
 * INIT_LIST_HEAD - Initialize a list_head structure
 * @list: list_head structure to be initialized.
 *
 * Initializes the list_head to point to itself.  If it is a list header,
 * the result is an empty list.
 */
 /**
*INIT_LIST_HEAD-初始化LIST_HEAD结构
*@list:要初始化的list_head结构。
*
*初始化list_head以指向其自身。如果它是列表报头，
*结果是一个空列表。
*/
static inline void INIT_LIST_HEAD(struct list_head *list)
{
	list->next = list;
	list->prev = list;
}

/*
 * Insert a new entry between two known consecutive entries.
 *
 * This is only for internal list manipulation where we know
 * the prev/next entries already!
 */
 /*
*在两个已知的连续条目之间插入一个新条目。
*
*这只适用于我们知道的内部列表操作
*上一个/下一个条目已经存在！
*/
static inline void __list_add(struct list_head *new,
			      struct list_head *prev,
			      struct list_head *next)
{
	next->prev = new;
	new->next = next;
	new->prev = prev;
	prev->next = new;
}

/**
 * list_add - add a new entry
 * @new: new entry to be added
 * @head: list head to add it after
 *
 * Insert a new entry after the specified head.
 * This is good for implementing stacks.
 */
 /**
*list_add-添加新条目
*@new:要添加的新条目
*@head：列出head添加到后面
*
*在指定的标题后插入一个新条目。
*这有利于实现堆栈。
*/
static inline void list_add(struct list_head *new, struct list_head *head)
{
	__list_add(new, head, head->next);
}

/**
 * list_add_tail - add a new entry
 * @new: new entry to be added
 * @head: list head to add it before
 *
 * Insert a new entry before the specified head.
 * This is useful for implementing queues.
 */
 /**
*list_add_tail-添加一个新条目
*@new:要添加的新条目
*@head：列出head添加之前
*
*在指定标题之前插入一个新条目。
*这对于实现队列很有用。
*/
static inline void list_add_tail(struct list_head *new, struct list_head *head)
{
	__list_add(new, head->prev, head);
}

/*
 * Delete a list entry by making the prev/next entries
 * point to each other.
 *
 * This is only for internal list manipulation where we know
 * the prev/next entries already!
 */
 /*
*通过创建上一个/下一个条目来删除列表条目
*相互指向。
*
*这只适用于我们知道的内部列表操作
*上一个/下一个条目已经存在！
*/
static inline void __list_del(struct list_head *prev, struct list_head *next)
{
	next->prev = prev;
	prev->next = next;
}

static inline void __list_del_entry(struct list_head *entry)
{
	__list_del(entry->prev, entry->next);
}

/**
 * list_del - deletes entry from list.
 * @entry: the element to delete from the list.
 * Note: list_empty() on entry does not return true after this, the entry is
 * in an undefined state.
 */
 /**
*list_del-从列表中删除条目。
*@entry：要从列表中删除的元素。
*注意：条目上的list_empty（）在此之后不会返回true，该条目为
*处于未定义状态。
*/
static inline void list_del(struct list_head *entry)
{
	__list_del_entry(entry);
	entry->next = LIST_POISON1;
	entry->prev = LIST_POISON2;
}

/**
 * list_is_head - tests whether @list is the list @head
 * @list: the entry to test
 * @head: the head of the list
 */
 /**
*list_is_head-测试@list是否为list@head
*@list:要测试的条目
*@head：名单之首
*/
static inline int list_is_head(const struct list_head *list, const struct list_head *head)
{
	return list == head;
}

/**
 * list_empty - tests whether a list is empty
 * @head: the list to test.
 */
 /**
*list_empty-测试列表是否为空
*@head：要测试的列表。
*/
static inline int list_empty(const struct list_head *head)
{
	return head->next == head;
}

/**
 * list_entry - get the struct for this entry
 * @ptr:	the &struct list_head pointer.
 * @type:	the type of the struct this is embedded in.
 * @member:	the name of the list_head within the struct.
 */
 /**
*list_entry-获取此条目的结构
*@ptr：&struct list_head指针。
*@type：它所嵌入的结构的类型。
*@member：结构中list_head的名称。
*/
#define list_entry(ptr, type, member) \
	container_of(ptr, type, member)

/**
 * list_first_entry - get the first element from a list
 * @ptr:	the list head to take the element from.
 * @type:	the type of the struct this is embedded in.
 * @member:	the name of the list_head within the struct.
 *
 * Note, that list is expected to be not empty.
 */
 /**
*list_first_entry-从列表中获取第一个元素
*@ptr：从中获取元素的列表头。
*@type：它所嵌入的结构的类型。
*@member：结构中list_head的名称。
*
*请注意，该列表不应为空。
*/
#define list_first_entry(ptr, type, member) \
	list_entry((ptr)->next, type, member)

/**
 * list_next_entry - get the next element in list
 * @pos:	the type * to cursor
 * @member:	the name of the list_head within the struct.
 */
 /**
*list_next_entry-获取列表中的下一个元素
*@pos:光标的类型*
*@member：结构中list_head的名称。
*/
#define list_next_entry(pos, member) \
	list_entry((pos)->member.next, typeof(*(pos)), member)

/**
 * list_entry_is_head - test if the entry points to the head of the list
 * @pos:	the type * to cursor
 * @head:	the head for your list.
 * @member:	the name of the list_head within the struct.
 */
 /**
*list_entry_is_head-测试条目是否指向列表的头部
*@pos:光标的类型*
*@head：你名单的标题。
*@member：结构中list_head的名称。
*/
#define list_entry_is_head(pos, head, member)				\
	(&pos->member == (head))

/**
 * list_for_each_entry - iterate over list of given type
 * @pos:	the type * to use as a loop cursor.
 * @head:	the head for your list.
 * @member:	the name of the list_head within the struct.
 */
 /**
*list_for_each_entry-迭代给定类型的列表
*@pos:要用作循环光标的类型*。
*@head：你名单的标题。
*@member：结构中list_head的名称。
*/
#define list_for_each_entry(pos, head, member)				\
	for (pos = list_first_entry(head, typeof(*pos), member);	\
	     !list_entry_is_head(pos, head, member);			\
	     pos = list_next_entry(pos, member))

/**
 * list_for_each_entry_safe - iterate over list of given type. Safe against removal of list entry
 * @pos:	the type * to use as a loop cursor.
 * @n:		another type * to use as temporary storage
 * @head:	the head for your list.
 * @member:	the name of the list_head within the struct.
 */
 /**
*list_for_each_entry_safe-迭代给定类型的列表。防止删除列表条目
*@pos:要用作循环光标的类型*。
*@n:另一种类型*用作临时存储
*@head：你名单的标题。
*@member：结构中list_head的名称。
*/
#define list_for_each_entry_safe(pos, n, head, member)			\
	for (pos = list_first_entry(head, typeof(*pos), member),	\
		n = list_next_entry(pos, member);			\
	     !list_entry_is_head(pos, head, member);			\
	     pos = n, n = list_next_entry(n, member))

#endif /* LIST_H */
