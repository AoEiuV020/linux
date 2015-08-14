	.file	"jpeg.c"
	.section	.rodata
.LC0:
	.string	"/dev/fb0"
.LC1:
	.string	"fb=%d\n"
.LC2:
	.string	"%u*%u=%u\n"
.LC3:
	.string	"vinfo.bits_per_pixel=%u\n"
.LC4:
	.string	"finfo.line_length=%u\n"
	.align 8
.LC5:
	.string	"vinfo.xres*vinfo.bits_per_pixel/8=%u\n"
.LC6:
	.string	"are you root?"
.LC7:
	.string	"wb"
.LC8:
	.string	"screen.jpg"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$1072, %rsp
	movl	$0, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	open
	movl	%eax, -12(%rbp)
	leaq	-288(%rbp), %rdx
	movl	-12(%rbp), %eax
	movl	$17922, %esi
	movl	%eax, %edi
	movl	$0, %eax
	call	ioctl
	leaq	-208(%rbp), %rdx
	movl	-12(%rbp), %eax
	movl	$17920, %esi
	movl	%eax, %edi
	movl	$0, %eax
	call	ioctl
	movl	-12(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	movl	-208(%rbp), %edx
	movl	-204(%rbp), %eax
	movl	%edx, %ecx
	imull	%eax, %ecx
	movl	-204(%rbp), %edx
	movl	-208(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	movl	-184(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	movl	-240(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC4, %edi
	movl	$0, %eax
	call	printf
	movl	-208(%rbp), %edx
	movl	-184(%rbp), %eax
	imull	%edx, %eax
	shrl	$3, %eax
	movl	%eax, %esi
	movl	$.LC5, %edi
	movl	$0, %eax
	call	printf
	movq	stdout(%rip), %rax
	movq	%rax, %rdi
	call	fflush
	cmpl	$-1, -12(%rbp)
	jne	.L2
	movl	$.LC6, %edi
	call	puts
	movl	$-1, %eax
	jmp	.L10
.L2:
	movl	-204(%rbp), %edx
	movl	-208(%rbp), %eax
	imull	%eax, %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	movl	%eax, %eax
	movq	%rax, %rdi
	call	malloc
	movq	%rax, -24(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L4
.L7:
	movl	$0, -8(%rbp)
	jmp	.L5
.L6:
	movl	-208(%rbp), %edx
	movl	-4(%rbp), %eax
	imull	%eax, %edx
	movl	%edx, %eax
	addl	%eax, %eax
	leal	(%rax,%rdx), %ecx
	movl	-8(%rbp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	addl	%ecx, %eax
	movl	%eax, -28(%rbp)
	leaq	-1072(%rbp), %rcx
	movl	-12(%rbp), %eax
	movl	$4, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	read
	movl	-28(%rbp), %eax
	movslq	%eax, %rdx
	movq	-24(%rbp), %rax
	addq	%rax, %rdx
	movl	-176(%rbp), %eax
	shrl	$3, %eax
	movl	%eax, %eax
	movzbl	-1072(%rbp,%rax), %eax
	movb	%al, (%rdx)
	movl	-28(%rbp), %eax
	cltq
	leaq	1(%rax), %rdx
	movq	-24(%rbp), %rax
	addq	%rax, %rdx
	movl	-164(%rbp), %eax
	shrl	$3, %eax
	movl	%eax, %eax
	movzbl	-1072(%rbp,%rax), %eax
	movb	%al, (%rdx)
	movl	-28(%rbp), %eax
	cltq
	leaq	2(%rax), %rdx
	movq	-24(%rbp), %rax
	addq	%rax, %rdx
	movl	-152(%rbp), %eax
	shrl	$3, %eax
	movl	%eax, %eax
	movzbl	-1072(%rbp,%rax), %eax
	movb	%al, (%rdx)
	addl	$1, -8(%rbp)
.L5:
	movl	-208(%rbp), %edx
	movl	-8(%rbp), %eax
	cmpl	%eax, %edx
	ja	.L6
	movl	-240(%rbp), %eax
	movl	-208(%rbp), %ecx
	movl	-184(%rbp), %edx
	imull	%ecx, %edx
	shrl	$3, %edx
	subl	%edx, %eax
	movl	%eax, %ecx
	movl	-12(%rbp), %eax
	movl	$1, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	lseek
	addl	$1, -4(%rbp)
.L4:
	movl	-204(%rbp), %edx
	movl	-4(%rbp), %eax
	cmpl	%eax, %edx
	ja	.L7
	leaq	-1056(%rbp), %rax
	movq	%rax, %rdi
	call	jpeg_std_error
	movq	%rax, -880(%rbp)
	leaq	-880(%rbp), %rax
	movl	$584, %edx
	movl	$90, %esi
	movq	%rax, %rdi
	call	jpeg_CreateCompress
	movl	$.LC7, %esi
	movl	$.LC8, %edi
	call	fopen
	movq	%rax, -40(%rbp)
	movq	-40(%rbp), %rdx
	leaq	-880(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	jpeg_stdio_dest
	movl	-208(%rbp), %eax
	movl	%eax, -832(%rbp)
	movl	-204(%rbp), %eax
	movl	%eax, -828(%rbp)
	movl	$3, -824(%rbp)
	movl	$2, -820(%rbp)
	leaq	-880(%rbp), %rax
	movq	%rax, %rdi
	call	jpeg_set_defaults
	leaq	-880(%rbp), %rax
	movl	$1, %esi
	movq	%rax, %rdi
	call	jpeg_start_compress
	jmp	.L8
.L9:
	movl	-536(%rbp), %edx
	movl	-832(%rbp), %eax
	imull	%eax, %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	movl	%eax, %edx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movq	%rax, -1064(%rbp)
	leaq	-1064(%rbp), %rcx
	leaq	-880(%rbp), %rax
	movl	$1, %edx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	jpeg_write_scanlines
.L8:
	movl	-536(%rbp), %edx
	movl	-828(%rbp), %eax
	cmpl	%eax, %edx
	jb	.L9
	leaq	-880(%rbp), %rax
	movq	%rax, %rdi
	call	jpeg_finish_compress
	leaq	-880(%rbp), %rax
	movq	%rax, %rdi
	call	jpeg_destroy_compress
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	free
	movl	-12(%rbp), %eax
	movl	%eax, %edi
	call	close
	movl	$0, %eax
.L10:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 5.2.0"
	.section	.note.GNU-stack,"",@progbits
