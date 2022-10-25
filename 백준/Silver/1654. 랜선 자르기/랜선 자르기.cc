#include <stdio.h>
#include <stdlib.h>
int compare(const void *a,const void *b) {
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if(num1 > num2) {
        return 1;
    }

    else if (num1 < num2) {
        return -1;
    }
    else {
        return 0;
    }
}

int main(void){
    int n;
    scanf("%d",&n);
    int k;
    scanf("%d",&k);
    int arr[n];
    for(int i = 0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    qsort(arr,n,sizeof(int), compare);

    long long max = 0;
    long long l = 1; //이부분이 다름
    long long r = arr[n-1];

    while(l<=r){
        int sum = 0;

        long long mid = (l+r)/2;

        for(int i = 0;i<n;i++) {
            if( mid != 0){
                sum = sum + (arr[i]/mid);
            }
        }

        if(sum < k){
            r = mid-1;
        }
        else if(sum>=k){

          l = mid+1;
            if(mid >= max){
                max = mid;
            }


        }
    }
 printf("%lld",r);
}
