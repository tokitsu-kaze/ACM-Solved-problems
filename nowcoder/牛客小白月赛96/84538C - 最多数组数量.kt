import java.util.*
import kotlin.math.*

fun readint()=readLine()!!.toInt()
fun readll()=readLine()!!.toLong()
fun readdb()=readLine()!!.toDouble()
fun readstring()=readLine()!!
fun readline_char()=readLine()!!.toCharArray()
fun readline_int()=(readLine()!!.split(" ").map{it.toInt()}).toIntArray()
fun readline_ll()=(readLine()!!.split(" ").map{it.toLong()}).toLongArray()
fun readline_db()=(readLine()!!.split(" ").map{it.toDouble()}).toDoubleArray()
fun readline_string()=(readLine()!!.split(" "))
fun main(args: Array<String>){go()}
data class pair(var fi:Long,var se:Long)
/*using: xxx.sortWith(cmp)*/
val cmp: Comparator<pair> = Comparator{ a,b->
	if (a.fi==b.fi) a.se.compareTo(b.se)
	else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=1e5.toInt()+10
const val mod=998244353
/*------------------------------------------------------------*/
fun go()
{
	var n=readint()
	require(n>=3 && n<=2e5)
	var a=readline_int()
	require(a.size==n)
	var bit=LongArray(n+5){0}
	for(i in 1..n)
	{
		require(a[i-1]>=1 && a[i-1]<=1e6)
		bit[i]=bit[i-1]+a[i-1]
	}
	var ans=0L
	var j=1
	for(i in 2..n-1)
	{
		while(j<i && bit[j]<bit[i]-bit[j] && bit[i]-bit[j]>bit[n]-bit[i]) j++
		if(j>1) j--
		if(bit[i]-bit[j]>bit[n]-bit[i]) ans+=j
	}
	println("${ans}")
}

