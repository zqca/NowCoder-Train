let patition = function(arr, low, high){
    //console.log("arr:"+arr+" low:"+low+" high:"+high);
    //let low = start, high = end;
    let cmp = arr[low];
    while(low < high){
        while(low < high && arr[high] >= cmp){
            --high;
        }
        arr[low] = arr[high];
        while(low < high && arr[low] <= cmp){
            ++low;
        }
        arr[high] = arr[low];
    }
    arr[low] = cmp;
    return low;
}
    

let myQuickSort = function(arr, low, high){
    if(low < high) {//TODO:这是递归结束出口！！
        let p = patition(arr, low, high);
        myQuickSort(arr, 0, p - 1);
        myQuickSort(arr, p + 1, high);
    }
}

let arr = [4, 5, 3, 7, 2, 6, 3];
myQuickSort(arr, 0, arr.length - 1);



