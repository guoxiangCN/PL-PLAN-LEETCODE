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

	// 6502CPU支持的中断类型
	enum InterupterType {
		kIRQ,
		kNMI,
		kBRK
	};

public:
	register_t A;            // 累加寄存器
	register_t X;            // X索引寄存器
	register_t Y;            // Y索引寄存器
	register_t PC;           // 程序计数器
	register_t SP;           // 栈指针寄存器

	FlagRegister Flag;      // 标志状态位寄存器
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