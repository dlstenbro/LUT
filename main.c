#include <stdio.h>
#include <stdlib.h>

#include "LUT.h"

int main()
{
    Pair *record =  malloc(sizeof(struct S_TEMP_DATA));
    record->temperature = 20;
    record->voltage = 10;

    Pair *record2 =  malloc(sizeof(struct S_TEMP_DATA));
    record2->temperature = 999;
    record2->voltage = -1;

    Pair *record3 =  malloc(sizeof(struct S_TEMP_DATA));
    record3->temperature = 555;
    record3->voltage = -77;

    Pair *record4 =  malloc(sizeof(struct S_TEMP_DATA));
    record4->temperature = 123;
    record4->voltage = 456;

    addRecord(record);
    addRecord(record2);
    addRecord(record3);

    printRecords();

    printf("\nRemoving record %d %d", record2->temperature, record2->voltage );
    deleteRecord(record2);
    printRecords();

    printf("\nFetching record %d %d\n", record4->temperature, record4->voltage );
    Pair* fetched = getRecord(record4);
    if(fetched == NULL)
    {
        printf("Record not found\n");
    }
    else{
        printf("%d %d\n", fetched->temperature, fetched->voltage);
    }

    return 0;
}
