两线程会运行到A_num+B_num=100为止，一次只写入1个单位，即num只加1。但会通过设随机数的方式在线程释放锁时sleep一段时间，从而模拟线程A、B的随机执行顺序。设置M=2，N=8，程序一开始假设线程A已写了M+1个单位，运行后，可以观测到差值始终在[3,7]之间，截取部分输出如下：
threadB has written data, now A length:16, B length:13, difference:3
threadA has written data, now A length:17, B length:13, difference:4
threadB has written data, now A length:17, B length:14, difference:3
threadA has written data, now A length:18, B length:14, difference:4
threadA has written data, now A length:19, B length:14, difference:5
threadB has written data, now A length:19, B length:15, difference:4
threadA has written data, now A length:20, B length:15, difference:5
threadA has written data, now A length:21, B length:15, difference:6
threadA has written data, now A length:22, B length:15, difference:7
threadB has written data, now A length:22, B length:16, difference:6
threadB has written data, now A length:22, B length:17, difference:5
threadA has written data, now A length:23, B length:17, difference:6
threadB has written data, now A length:23, B length:18, difference:5
threadB has written data, now A length:23, B length:19, difference:4
threadA has written data, now A length:24, B length:19, difference:5
编译命令需加-pthread 