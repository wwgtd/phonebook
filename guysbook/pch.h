#ifndef PCH_H
#define PCH_H

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstddef>


struct Record;

char * field(Record & rcrd, const char* Id); 

// operators

int add(std::fstream & fst, char * args[]);

int count(std::fstream & fst);

bool edit(std::fstream & fst, char * args[]);

struct Record
{
	char firstname[50];
	char lastname[50];
	char patronomic[50];
	char birthday[50];
	char adress[50];
	char phone[20];
	char note[4096];
};




struct FieldMap
{
	char   Id[20];
	size_t offset;
} fields[] = {
#define RegField(FIELD) {#FIELD, offsetof(Record,  FIELD)}
	RegField(firstname),
	RegField(lastname),
	RegField(patronomic),
	RegField(birthday),
	RegField(adress),
	RegField(phone),
	RegField(note)
#undef RegField
};




// ./prog edit ...
/*
	add F I O Db Adr Ph Notes -> N
	edit n fieldId -> OK/error
	del n -> OK/error
	find HeldId regexp -> n |...| or NULL
	list //n1 n2 -> n |...| or NULL
	count -> n
*/

#endif 
