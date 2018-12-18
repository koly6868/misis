#ifndef DYNAMIC_ARRAY_2018
#define DYNAMIC_ARRAY_2018

class Dynamic_array
{
public:
	Dynamic_array() = default;
	Dynamic_array(const int size);
	Dynamic_array(const Dynamic_array& arr);
	~Dynamic_array();
	double& operator[](int index) const;
  Dynamic_array& operator=(const Dynamic_array& arr);
	int GetSize() const;
  void Resize(const int size);

private:
	double* arr_{nullptr};
	int size_{0};
};



#endif //DYNAMIC_ARRAY_2018
