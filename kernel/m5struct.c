/*
 * Copyright (c) 2005
 * The Regents of The University of Michigan
 * All Rights Reserved
 *
 * This code is part of the M5 simulator, developed by Nathan Binkert,
 * Erik Hallnor, Steve Raasch, and Steve Reinhardt, with contributions
 * from Ron Dreslinski, Dave Greene, Lisa Hsu, Kevin Lim, Ali Saidi,
 * and Andrew Schultz.
 *
 * Permission is granted to use, copy, create derivative works and
 * redistribute this software and such derivative works for any
 * purpose, so long as the copyright notice above, this grant of
 * permission, and the disclaimer below appear in all copies made; and
 * so long as the name of The University of Michigan is not used in
 * any advertising or publicity pertaining to the use or distribution
 * of this software without specific, written prior authorization.
 *
 * THIS SOFTWARE IS PROVIDED AS IS, WITHOUT REPRESENTATION FROM THE
 * UNIVERSITY OF MICHIGAN AS TO ITS FITNESS FOR ANY PURPOSE, AND
 * WITHOUT WARRANTY BY THE UNIVERSITY OF MICHIGAN OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE. THE REGENTS OF THE UNIVERSITY OF MICHIGAN SHALL NOT BE
 * LIABLE FOR ANY DAMAGES, INCLUDING DIRECT, SPECIAL, INDIRECT,
 * INCIDENTAL, OR CONSEQUENTIAL DAMAGES, WITH RESPECT TO ANY CLAIM
 * ARISING OUT OF OR IN CONNECTION WITH THE USE OF THE SOFTWARE, EVEN
 * IF IT HAS BEEN OR IS HEREAFTER ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGES.
 */

#include <stddef.h>
#include <asm/page.h>
#include <linux/dcache.h>
#include <linux/fs.h>
#include <linux/path.h>
#include <linux/sched.h>
#include <linux/mm_types.h>

/*
 * Structure size information
 */
const int thread_info_size = sizeof(struct thread_info);
const int thread_info_task = offsetof(struct thread_info, task);

const int task_struct_size = sizeof(struct task_struct);
const int task_struct_pid = offsetof(struct task_struct, pid);
const int task_struct_start_time = offsetof(struct task_struct, start_time);
const int task_struct_tgid = offsetof(struct task_struct, tgid);
const int task_struct_comm = offsetof(struct task_struct, comm);
const int task_struct_comm_size = TASK_COMM_LEN;
const int task_struct_mm = offsetof(struct task_struct, mm);

/*
 * Virtual Memory structures
 */
const int mm_struct_size = sizeof(struct mm_struct);
// mm_struct ptr
const int mm_struct_mmap = offsetof(struct mm_struct, mmap);
const int vm_area_struct_size = sizeof(struct vm_area_struct);
const int vm_area_struct_vm_start = offsetof(struct vm_area_struct, vm_start);
const int vm_area_struct_vm_end = offsetof(struct vm_area_struct, vm_end);
const int vm_area_struct_vm_flags = offsetof(struct vm_area_struct, vm_flags);
const int vm_area_struct_vm_pgoff = offsetof(struct vm_area_struct, vm_pgoff);
const int vm_page_size = PAGE_SIZE;
// vm_area_struct ptr
const int vm_area_struct_vm_next = offsetof(struct vm_area_struct, vm_next);
// file ptr
const int vm_area_struct_vm_file = offsetof(struct vm_area_struct, vm_file);

/*
 * File structures
 */ 
const int file_struct_size = sizeof(struct file);
// path ptr
const int file_struct_f_path = offsetof(struct file, f_path);

const int path_struct_size = sizeof(struct path);
// dentry ptr
const int path_struct_dentry = offsetof(struct path, dentry);

const int dentry_struct_size = sizeof(struct dentry);
// dentry ptr
const int dentry_struct_d_parent = offsetof(struct dentry, d_parent);
const int dentry_struct_d_name = offsetof(struct dentry, d_name);

const int qstr_struct_size = sizeof(struct qstr);
// char*
const int qstr_struct_name = offsetof(struct qstr, name);
const int qstr_struct_len = offsetof(struct qstr, len);
