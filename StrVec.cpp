#include "StrVec.h"

void StrVec::push_back(const std::string& s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

std::pair<std::string*,std::string*>
StrVec::alloc_n_copy(const std::string* b, const std::string* e)
{
	auto data = alloc.allocate(e - b);
	return{ data, std::uninitialized_copy(b, e, data) };
}

void StrVec::free()
{
	if (elements)
	{
		for (auto p = first_free; p != elements;)
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}
}

StrVec::StrVec(const StrVec& rhs)
{
	auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}
//ex13.40
StrVec::StrVec(std::initializer_list<std::string> il)
{
	range_initialize(il.begin(), il.end());
}

StrVec::~StrVec()
{
	free();
}

StrVec& StrVec::operator=(const StrVec& rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

void StrVec::alloc_n_move(size_t new_cap)
{
	auto newdata = alloc.allocate(new_cap);
	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + new_cap;
}

void StrVec::reallocate()
{
	auto newcapacity = size() ? 2 * size() : 1;
	alloc_n_move(newcapacity);
}

//ex13.40
void StrVec::range_initialize(const std::string* first, const std::string* last)
{
	auto newdata = alloc_n_copy(first, last);
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec::StrVec(StrVec &&s) noexcept
: elements(s.elements), first_free(s.first_free), cap(s.cap){
    s.elements = s.first_free = s.cap = nullptr;
}

StrVec& StrVec::operator=(StrVec &&rhs) noexcept {
    if (this != &rhs) {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}


StrVec& StrVec::operator=(std::initializer_list<std::string> il) {
    auto data = alloc_n_copy(il.begin(), il.end());
    free();
    elements = data.first;
    return *this;
}


std::string& StrVec::operator[](std::size_t n) {
    return elements[n];
}

const std::string& StrVec::operator[](std::size_t n) const {
    return *(elements + n);
}
