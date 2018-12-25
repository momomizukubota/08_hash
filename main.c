#include <stdio.h>
#include <string.h>

#define HASH_SIZE 10
#define DATA_SIZE 258




/*
	input3.txt��1�s�ڂ�256�����H?
	

	����
	�n�b�V���e�[�u���̃T�C�Y��10�Ƃ��܂��B����ȏ�ɒǉ����悤�Ƃ��Ă�������������Ȃ����̂Ƃ��܂��B
	�e������̕�������255�����𒴂��܂���B

*/



void trim(char* str)
{
	char *p;
	p = strchr(str, '\n');
	if (p != NULL) {
		*p = '\0';
	}
}


int isOpen(char hashTable[][DATA_SIZE], int hashNum)
{
	if (hashTable[hashNum][0] == '\0')
	{
		return 1;
	}

	return 0;
}

int main(int argc, char *argv[])
{
	//������
	char str[DATA_SIZE];
	char hashTable[HASH_SIZE][DATA_SIZE];
	for (int i = 0; i < HASH_SIZE; hashTable[i][0] = '\0', i++);

	while (fgets(str, sizeof(str), stdin))
	{
		trim(str);


		//�ꗗ�\��
		if (str[0] == '\0')
		{
			for (int i = 0; i < HASH_SIZE; i++)
			{
				if (i != 0)
				{
					printf(",");
				}

				for (char *p = hashTable[i]; *p != '\0'; *p++) printf("%c", *p);
			}
			printf("\n");
		}

		//HASH TABLE�ւ̒ǉ�
		else
		{

			int hashNum = 0;
			char *p = str;
			for (; *p != '\0'; hashNum += (int)*p++);
			hashNum %= 10;


			for (int i = 0; i < HASH_SIZE; i++)
			{
				if (isOpen(hashTable, hashNum))
				{
					strcpy_s(hashTable[hashNum], sizeof(char) * DATA_SIZE, str);
					break;
				}
				else
				{
					hashNum = (hashNum + 1) % 10;
				}
			}
		}

	}
	return 0;
}
