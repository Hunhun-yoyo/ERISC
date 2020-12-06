#ifndef RISC_H
#define RISC_H
class RISC
{
    private:
        unsigned char* Stack;
        unsigned char* Memory;
        int* Register;
        unsigned char* RegisterStatus;
        unsigned char* MemoryStatus;
        unsigned char StackStatus;

    public:
        RISC();
        void Load(int rd, int rs);
        void Store(int rs, int rd);
        void Push(int rs);
        void Pop(int rd);
        void Mov(int rd, int rs);
        void Add(int rd, int rs1, int rs2);
        void Sub(int rd, int rs1, int rs2);
        void Mul(int rd, int rs1, int rs2);
        void Div(int rd, int rs1, int rs2);
        void Rem(int rd, int rs1, int rs2);
        void And(int rd, int rs1, int rs2);
        void Or(int rd, int rs1, int rs2);
        void WriteRegister(int rd);
        void ReadRegister(int rd);
        void ReadWriteMemory(int rd);
        void UseStack();
};
#endif //RISC_H