Ftrace
======

内核源码位置 src/kernel/trace:

/sys/kernel/debug/tracing

	root@v:/sys/kernel/debug/tracing# ls
	available_events            events                    per_cpu              set_ftrace_notrace  trace                tracing_on
	available_filter_functions  free_buffer               printk_formats       set_ftrace_pid      trace_clock          tracing_thresh
	available_tracers           function_profile_enabled  README               set_graph_function  trace_marker         uprobe_events
	buffer_size_kb              instances                 saved_cmdlines       set_graph_notrace   trace_options        uprobe_profile
	buffer_total_size_kb        kprobe_events             saved_cmdlines_size  snapshot            trace_pipe
	current_tracer              kprobe_profile            set_event            stack_max_size      trace_stat
	dyn_ftrace_total_info       max_graph_depth           set_event_pid        stack_trace         tracing_cpumask
	enabled_functions           options                   set_ftrace_filter    stack_trace_filter  tracing_max_latency



	buffer_size_kb：这个属性比較重要，也是使用中须要注意的，这是设置启动的CPU的缓存大小。取决于追踪log的大小，超出会反复利用覆盖，可是一次性分配又须要考虑内存。
	buffer_total_size_kb：这个就是总和buffer size 了，启用了多少个cpu去trace就乘以buffer_size_kb.
	current_tracer: 当前的追踪器。有哪几种能够查看available_tracers ,用echo * > 重定向 设置改变，详细tracer的不同需另行參考 ，默觉得nop
	events：文件夹下就是加入在kernel源代码中已经存在的各个event集合。
	free_buffer：顾名思义，可是这个使用方法比較特殊，有仅仅要open之后。等处理完buffer之后 close这个文件就可以释放buffer，有兴趣能够去trace.c里面看看这个节点的file_operation，不手动去close这个节点的话，上面设置的buffer是不会free的。
	trace:用于追踪操作的文件节点，就是读取该节点获取trace log
	tracing_cpumask：用到的cpu标记。以数值bit位表示多少个cpu，这个尤为注意。比方四核 cat显示就是 f 也就是1111。
	tracing_on：开关


	
