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
inline fun <T:Number> lower_bound_pos(
a:MutableList<T>,L:Int,R:Int,target:T):Int{
	var l=L
	var r=R
	var mid:Int
	while(l<r){
    	mid=(l+r) shr 1
    	if(a[mid].toLong()>=target.toLong()) r=mid
    	else l=mid+1
    }
	return l
}
data class pair(var fi:Int,var se:Int)
/*using: xxx.sortWith(cmp)*/
val cmp: Comparator<pair> = Comparator{ a,b->
    if (a.fi==b.fi) a.se.compareTo(b.se)
    else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=1e5.toInt()+10
const val mod=(1e9).toInt()+7
/*------------------------------------------------------------*/
fun go()
{
	var n=readint()
	require(n>=1 && n<=1e5)
	var a=readline_int()
	require(a.size==n)
	var x=readint()
	require(x>=2 && x<=1e9)
	var mp=LongArray(105){0}
	for(it in a)
	{
		require(it>=1 && it<=1e9)
		var cnt=0
		var now=1L
		var t=it
		while(t>x)
		{
			t=(t+2)/3
			now=now*2L
			cnt++
		}
		if(t==x) mp[cnt]+=now
	}
	var ans=0L
	for(it in mp) ans=max(ans,it)
	println("${ans}")
}

