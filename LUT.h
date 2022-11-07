/*
typedef struct temperature {
0.793,	-40
1.000,	-35
1.226,	-30
3.288,	125
...
...
...
}
*/

// data structure for linked list
typedef struct S_TEMP_DATA {
    int voltage;
    int temperature;

    struct S_TEMP_DATA *next;
} Pair;

Pair *head = NULL; // linked list head

/*
    parameters:
        record is the value to add

    return: None
*/
void addRecord(Pair *new_record)
{
    printf("Adding new record: %d %d\n", new_record->temperature, new_record->voltage);

    // check to see if there is a "head" node
    // if so, this is the first record in the list
    if( head == NULL)
    {
        head = new_record;
        //printf("Head is now record  %d %d\n\n", head->temperature, head->voltage);
    }
    else
    {
        Pair *current = head;

        while(current != NULL)
        {
            if(current->next == NULL)
            {
                current->next = new_record;
                break;
            }
            current = current->next;
        }
    }
}

/*
    parameters:
        record is the value to delete

    return: None
*/
void deleteRecord(Pair *record)
{
    Pair *current = head;
    Pair *temp = NULL;

    while(current != NULL)
    {
        if(current == record)
        {
            head = current->next;
        }
        else if(current->next == record)
        {
            temp = current->next;
            current->next = temp->next;
        }
        current = current->next;
    }
}

/*
    parameters:
        record is the value to find

    return: The Pair object if found otherwise,
            return NULL
*/
Pair* getRecord(Pair *record)
{
    Pair *current = head;
    Pair *match = NULL;

    while(current != NULL)
    {
        if(record == current)
        {
            match = current;
            break;
        }
        current = current->next;
    }

    return match;    
}

/*
    Print all records in linked list
*/
void printRecords()
{
    Pair *current = head;
    
    printf("\n\n**** Voltage Temperature ****\n");
    while(current != NULL)
    {
        printf("%d %d\n", current->voltage, current->temperature);
        current = current->next;
    }
}