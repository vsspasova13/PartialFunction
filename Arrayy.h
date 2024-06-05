#pragma once
class Arrayy
{
	private:
		int* data;
		int size;

		void free();
		void copyFrom(const Arrayy& other);
		void moveFrom(Arrayy&& other);
	public:
		Arrayy();
		Arrayy(int* data, int size);
		Arrayy& operator=(const Arrayy& other);
		Arrayy(const Arrayy& other);
		Arrayy& operator=( Arrayy&& other) noexcept;
		Arrayy( Arrayy&& other)noexcept;
		~Arrayy();

		int operator[](int index) const;
		const int* getData()const;
		int getSize() const;
	
};

