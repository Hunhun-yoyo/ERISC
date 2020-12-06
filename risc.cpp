#include "risc.h"
// 寄存器写入为1，读取为2，读写为3 内存读写为1
// 栈操作过为1
RISC::RISC()
{
    Stack = new unsigned char[1024 * 1024];
    Memory = new unsigned char[1024 * 1024];
    Register = new int[32];
    RegisterStatus = new unsigned char[32];
    MemoryStatus = new unsigned char[16];
    StackStatus = 0;
    for(int i = 0; i < 32; i++)
    {
        RegisterStatus[i] = 0;
    }
    for(int i = 0; i < 32; i++)
    {
        MemoryStatus[i] = 0;
    }
}

void RISC::WriteRegister(int rd)
{
    switch(RegisterStatus[rd])
    {
        case 0:
        RegisterStatus[rd] = 1;
        break;
        default:
        RegisterStatus[rd] = 3;
        break;
    }
}

void RISC::ReadRegister(int rd)
{
    switch(RegisterStatus[rd])
    {
        case 0:
        RegisterStatus[rd] = 2;
        break;
        default:
        RegisterStatus[rd] = 3;
        break;
    }
}

void RISC::ReadWriteMemory(int rd)
{
    MemoryStatus[rd / (1024 * 1024 / 16)] = 1;
}

void RISC::UseStack()
{
    StackStatus = 1;
}


void RISC::Load(int rd, int rs)
{
    Stack[rd] = Memory[Stack[rs]];
    ReadRegister(rs);
    WriteRegister(rd);
    ReadWriteMemory(Stack[rs]);
}

void RISC::Store(int rd, int rs)
{

}





