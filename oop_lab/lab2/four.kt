//finding the smallest and largest element in the array
fun main() {
    val arr = IntArray(20){(1..100).random()}
    arr.forEach { index -> print("$index\t")}
    var greatest = arr[0]
    var smallest = arr[0]
    arr.forEach {
        if(it < smallest){smallest = it}
        if(it > greatest){greatest = it}
    }
    println("\nGreatest element is $greatest")
    println("Smallest element is $smallest")
}