package collection

import kotlin.String

object Demo {

    fun main(a: Int): Int {
        println(a)
        return main(a + 1)
    }
}

fun main(array: Array<String>) {
    val linkedQueue = LinkedQueue<String>()

    for (i in 0..10) {
        linkedQueue.add(i.toString())
    }

    linkedQueue.remove()

    for (i in 0 until linkedQueue.size()) {
        print(linkedQueue.remove())
    }

    Demo.main(1)
}