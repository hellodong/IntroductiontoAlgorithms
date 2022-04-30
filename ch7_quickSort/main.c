

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>


#define ARRSIZE		(104857600)

#define swap(a,b) {a=a^b;b=a^b;a=a^b;}


static int array_quick[ARRSIZE];
static int array_inset[ARRSIZE];

static void swap_ptr(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}


void outputArray(int arr[], int length)
{
	int idx;
	for(idx = 0;idx < length;idx++) {
		if (idx % 16 == 0) {
			printf("\n");
		}
		printf("%8d ",arr[idx]);
		
	}
	printf("\n");
}

static int partition(int arr[], int start, int end)
{
	int leftIdx,rightIdx;
	leftIdx=start - 1;
	rightIdx=start;
	while(rightIdx < end) {
		if (arr[rightIdx] <= arr[end] ){
			leftIdx++;
            if (leftIdx != rightIdx) {
			    swap(arr[leftIdx], arr[rightIdx]);
            }
		}
		rightIdx++;
	}
    if (leftIdx + 1 != end) {
	    swap(arr[leftIdx + 1], arr[end]);
    }
	return leftIdx + 1;
}

static void quickSortRecursive(int arr[], int start, int end)
{
    if (start < end) {
        int q = partition(arr, start, end);
        quickSortRecursive(arr, start, q - 1);
        quickSortRecursive(arr,q + 1, end);
    }
}

static void quickSortIterat(int arr[], int start, int end)
{
    struct stack{
        int left;
        int right;
    };

    struct stack *tuple = NULL;
    struct stack stackTuple[1024];
    if (end - start + 1 > 1024) {
        int len = end - start + 1;
        tuple = (struct stack *)malloc(sizeof(struct stack) * len);
    }else{
        tuple = stackTuple;
    }
    int top = 0;
    tuple[top].left = start;
    tuple[top].right = end;
    while(top >= 0) {
        int left, right;
        left = tuple[top].left;
        right = tuple[top].right;
        top--;
        int q = partition(arr, left, right);
        if (left < q - 1 ) {
            ++top;
            tuple[top].left = left;
            tuple[top].right = q - 1;
        }

        if (right > q + 1) {
            ++top;
            tuple[top].left = q + 1;
            tuple[top].right = right;
        }
    }
    if (end - start + 1 > 1024) {
        free(tuple);
    }
}

static void bubleSort(int arr[], int len)
{
	int i,j;
	for (i = len - 1;i > 0;i--){
		for (j = 0;j < i;j++) {
			if (arr[j] > arr[j+1]){
				//swap_ptr(&arr[j], &arr[j + 1]);
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

static void selectSort(int arr[], int len)
{
	int i,j;
	for (i = 0;i < len - 1;i++){
		int cur_idx = i;
		for (j = i + 1;j < len;j++){
			if (arr[j] < arr[cur_idx]) {
				cur_idx = j;
			}
		}
		if (cur_idx != i) {
			swap(arr[i],arr[cur_idx]);
		}
	}
}

static void insertSort(int arr[], int len)
{
	for (int idx = 1;idx < len;idx++) {
		for (int jdx = idx;jdx > 0;jdx--) {
				if (arr[jdx] < arr[jdx - 1]) {
					swap(arr[jdx], arr[jdx - 1]);
				}else{
					break;
				}
		}
	}

}

void *thread_insertSort(void *arg)
{
    int *array = (int *)arg;
	struct timeval tv1,tv2;


	gettimeofday(&tv1, NULL);
	selectSort(array, ARRSIZE);
	gettimeofday(&tv2, NULL);
	printf("select sort spent time %dms\n", (tv2.tv_sec - tv1.tv_sec) * 1000 + tv2.tv_usec / 1000 - tv1.tv_usec/ 1000);
}

int main(void)
{
	srand(time(NULL));
	for (int idx = 0;idx < sizeof(array_quick)/sizeof(array_quick[0]);idx++){
        if (ARRSIZE > 4096)
        {
		    array_quick[idx] = rand() % ARRSIZE;
            array_inset[idx] = array_quick[idx];
        }else{
            array_quick[idx] = rand() ;
            array_inset[idx] = array_quick[idx];
        }
        //array_buble[idx] = array_quick[idx];
	}

    printf("start sort\n");
	//outputArray(array, sizeof(array) / sizeof(array[0]));
	//int pviot_idx = partition(array, 0, sizeof(array) / sizeof(array[0]) - 1);
	//printf("pviot index %d\n", pviot_idx);

	struct timeval tv1,tv2;

	//outputArray(array_quick, sizeof(array_quick) / sizeof(array_quick[0]));

	//gettimeofday(&tv1, NULL);
	//bubleSort(array_buble, sizeof(array_buble) / sizeof(array_buble[0]));
	//selectSort(array_quick, sizeof(array_quick) / sizeof(array_quick[0]));
	//insertSort(array_quick, sizeof(array_quick) / sizeof(array_quick[0]));
	//gettimeofday(&tv2, NULL);
	//printf("bubble sort spent time %dms\n", (tv2.tv_sec - tv1.tv_sec) * 1000 + tv2.tv_usec / 1000 - tv1.tv_usec/ 1000);
	//outputArray(array_buble, sizeof(array_buble) / sizeof(array_buble[0]));

    pthread_t sort_tid;
    pthread_create(&sort_tid, NULL, thread_insertSort, (void *)array_inset);

	gettimeofday(&tv1, NULL);
	quickSortIterat(array_quick, 0, ARRSIZE - 1);
	gettimeofday(&tv2, NULL);
	printf("quick sort spent time %dms\n", (tv2.tv_sec - tv1.tv_sec) * 1000 + tv2.tv_usec / 1000 - tv1.tv_usec/ 1000);
    if (ARRSIZE > 2048) {
	    outputArray(array_quick, 2048);
    }else{
	    outputArray(array_quick, sizeof(array_quick) / sizeof(array_quick[0]));
    }

    pthread_join(sort_tid, NULL);

	return 0;
}
