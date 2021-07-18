#include"linearlist.h"
template<typename T>
T sequential_list<T>::getElem(int index,T*element)
{
	element = data[index];
	return *element;
}
template<typename T>
int sequential_list<T>::locateElem(T element)
{
	for(int i=0;i<length;++i)
	{
		if (data[i] == element)
		{
			return i;
		}
	}
	return 0;

}
template<typename T>
bool sequential_list<T>::listInsert(int index, T elemnet)
{
	if (index >= length && index < 0)
	{
		return 0;
	}
	if (length + 1 > MAXSIZE)
	{
		return 0;
	}//现在还不实现动态数组，小甲鱼没有说，不过应该可以实现
	++length;
	for (int i=length-1;i>index;--i)
	{
		data[i] = data[i - 1];
	}
	data[index] = elemnet;
	return 1;

}
template<typename T>
T sequential_list<T>::listDelete(int index, T* element)
{
	if (index<0 || index>length - 1)
	{
		return 0;
	}
	if (length - 1 < 0)
	{
		return 0;
	}
	*element = data[index];
	for (int i = index; i < length; ++i)
	{
		data[i] = data[i + 1];
	}
	--length;
	return *element;
}