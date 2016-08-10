#ifndef MBR_H_INCLUDED
#define MBR_H_INCLUDED

typedef struct MBR{
    int mbrSize;
    char* mbrDate;
    int mbrDiskSignature;
}MBR;

#endif // MBR_H_INCLUDED
