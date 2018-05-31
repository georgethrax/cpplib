#ifndef __BITMAP__
#define __BITMAP__

// By georgethrax, May 30, 2018.

class Bitmap{
public:
	int capacity;
	int *buf;
	int seg;
	int mod_bit;
	Bitmap(int n){
		capacity = n;
		buf = new int[capacity];
		seg = 32; // 8 * sizeof(int);
		mod_bit = 5; // 2 >> 5 == 32
	}
	~Bitmap(){
		delete []buf;
	}

	void clearAll(){
		memset(buf, 0, capacity*sizeof(int));
	}
	void set(int pos, bool flag){		
		if (flag){
			set(pos);
		}
		else{
			reset(pos);
		}
	}
	void set(int pos){
		int index = pos >> mod_bit ;//pos / 32 <==> pos >> 5;
		int offset = pos & (seg - 1); // 取最低位的5个比特， seg - 1 == 31 == 011111
		buf[index] |= 1 << offset;
	}
	void reset(int pos){
		int index = pos >> mod_bit ;//pos / 32 <==> pos >> 5;
		int offset = pos & (seg - 1); // 取最低位的5个比特， seg - 1 == 31 == 011111
		buf[index] &= ~(1 << offset);
	}
	bool get(int pos){
		int index = pos >> mod_bit ;//pos / 32 <==> pos >> 5;
		int offset = pos & (seg - 1); // 取最低位的5个比特， seg - 1 == 31 == 011111
		return buf[index] & (1 << offset);
	}

};

#endif