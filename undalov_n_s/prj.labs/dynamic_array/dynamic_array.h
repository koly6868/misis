#ifndef dynamic_array_2018
#define dynamic_array_2018

class Dynamic_array
{
public:
	Dynamic_array() = default;
	Dynamic_array(const int size);
	Dynamic_array(const Dynamic_array& arr);
	~Dynamic_array();
	double& operator[](int index) const;
	int GetSize() const;
private:
	double* _arr{nullptr};
	int _size{0};
};



#endif dynamic_array_2018
