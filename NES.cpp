#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

namespace arch6502 {

typedef uint8_t register_t;

template<int SHIFT, typename T = uint8_t>
struct Bit {
	T data;
	enum { mask  = 1 << (SHIFT - 1) };

	void Set() {
		data |= mask;
	}
	void Clear() {
		data &= (~mask);
	}

	bool IsSetted() {
		return data & mask;
	}
};

// https://blog.csdn.net/qq_34254642/article/details/104217290
union FlagRegister {
	uint8_t raw;
	Bit<1> Carry;
	Bit<2> Zero;
	Bit<3> Interupt;
	Bit<4> D;
	Bit<5> Break;
	Bit<6> NOT_USED;
	Bit<7> V;
	Bit<8> Negative;
};

static_assert(sizeof(FlagRegister)==1,"sizeof(FlagRegister) <> 1byte");

class CPU {
public:

	// 6502CPU֧�ֵ��ж�����
	enum InterupterType {
		kIRQ,
		kNMI,
		kBRK
	};

public:
	register_t A;            // �ۼӼĴ���
	register_t X;            // X�����Ĵ���
	register_t Y;            // Y�����Ĵ���
	register_t PC;           // ���������
	register_t SP;           // ջָ��Ĵ���

	FlagRegister Flag;      // ��־״̬λ�Ĵ���
};

class PPU {

};

class RAM {

};

}





int main(int argc, char** argv)
{
	arch6502::CPU cpu;
	std::memset(&cpu, 0, sizeof(arch6502::CPU));

	std::cout << "Carray IsSet : " << std::boolalpha << cpu.Flag.Carry.IsSetted() << std::endl;
	cpu.Flag.Carry.Set();
	std::cout << "Carray IsSet : " << std::boolalpha << cpu.Flag.Carry.IsSetted() << std::endl;
	cpu.Flag.Carry.Clear();
	std::cout << "Carray IsSet : " << std::boolalpha << cpu.Flag.Carry.IsSetted() << std::endl;

	return 0;
}