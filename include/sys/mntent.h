/*****************************************************************************\
 *  Copyright (C) 2007-2010 Lawrence Livermore National Security, LLC.
 *  Copyright (C) 2007 The Regents of the University of California.
 *  Produced at Lawrence Livermore National Laboratory (cf, DISCLAIMER).
 *  Written by Brian Behlendorf <behlendorf1@llnl.gov>.
 *  UCRL-CODE-235197
 *
 *  This file is part of the SPL, Solaris Porting Layer.
 *  For details, see <http://github.com/behlendorf/spl/>.
 *
 *  The SPL is free software; you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License as published by the
 *  Free Software Foundation; either version 2 of the License, or (at your
 *  option) any later version.
 *
 *  The SPL is distributed in the hope that it will be useful, but WITHOUT
 *  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 *  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 *  for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with the SPL.  If not, see <http://www.gnu.org/licenses/>.
\*****************************************************************************/

#ifndef _SPL_MNTENT_H
#define _SPL_MNTENT_H

#define	MNTTAB		"/proc/mounts"
#define	VFSTAB		"/etc/vfstab"
#define	MNTMAXSTR	128

#define	MNTTYPE_ZFS	"zfs"		/* ZFS file system */
#define	MNTTYPE_UFS	"ufs"		/* Unix file system */
#define	MNTTYPE_SMBFS	"smbfs"		/* SMBFS file system */
#define	MNTTYPE_NFS	"nfs"		/* NFS file system */
#define	MNTTYPE_NFS3	"nfs3"		/* NFS Version 3 file system */
#define	MNTTYPE_NFS4	"nfs4"		/* NFS Version 4 file system */
#define	MNTTYPE_CACHEFS	"cachefs"	/* Cache File System */
#define	MNTTYPE_PCFS	"pcfs"		/* PC (MSDOS) file system */
#define	MNTTYPE_PC	MNTTYPE_PCFS	/* Deprecated name; use MNTTYPE_PCFS */
#define	MNTTYPE_LOFS	"lofs"		/* Loop back file system */
#define	MNTTYPE_LO	MNTTYPE_LOFS	/* Deprecated name; use MNTTYPE_LOFS */
#define	MNTTYPE_HSFS	"hsfs"		/* High Sierra (9660) file system */
#define	MNTTYPE_SWAP	"swap"		/* Swap file system */
#define	MNTTYPE_TMPFS	"tmpfs"		/* Tmp volatile file system */
#define	MNTTYPE_AUTOFS	"autofs"	/* Automounter ``file'' system */
#define	MNTTYPE_MNTFS	"mntfs"		/* In-kernel mnttab */
#define	MNTTYPE_DEV	"dev"           /* /dev file system */
#define	MNTTYPE_CTFS	"ctfs"		/* Contract file system */
#define	MNTTYPE_OBJFS	"objfs"		/* Kernel object file system */
#define	MNTTYPE_SHAREFS	"sharefs"	/* Kernel sharetab file system */


#define	MNTOPT_RO	"ro"		/* Read only */
#define	MNTOPT_RW	"rw"		/* Read/write */
#define	MNTOPT_RQ	"rq"		/* Read/write with quotas */
#define	MNTOPT_QUOTA	"quota"		/* Check quotas */
#define	MNTOPT_NOQUOTA	"noquota"	/* Don't check quotas */
#define	MNTOPT_ONERROR	"onerror"	/* action to taken on error */
#define	MNTOPT_SOFT	"soft"		/* Soft mount */
#define	MNTOPT_SEMISOFT	"semisoft"	/* partial soft, uncommited interface */
#define	MNTOPT_HARD	"hard"		/* Hard mount */
#define	MNTOPT_SUID	"suid"		/* Both setuid and devices allowed */
#define	MNTOPT_NOSUID	"nosuid"	/* Neither setuid nor devices allowed */
#define	MNTOPT_DEVICES	"devices"	/* Device-special allowed */
#define	MNTOPT_NODEVICES	"nodevices"	/* Device-special disallowed */
#define	MNTOPT_SETUID	"setuid"	/* Set uid allowed */
#define	MNTOPT_NOSETUID	"nosetuid"	/* Set uid not allowed */
#define	MNTOPT_GRPID	"grpid"		/* SysV-compatible gid on create */
#define	MNTOPT_REMOUNT	"remount"	/* Change mount options */
#define	MNTOPT_NOSUB	"nosub"		/* Disallow mounts on subdirs */
#define	MNTOPT_MULTI	"multi"		/* Do multi-component lookup */
#define	MNTOPT_INTR	"intr"		/* Allow NFS ops to be interrupted */
#define	MNTOPT_NOINTR	"nointr"	/* Don't allow interrupted ops */
#define	MNTOPT_PORT	"port"		/* NFS server IP port number */
#define	MNTOPT_SECURE	"secure"	/* Secure (AUTH_DES) mounting */
#define	MNTOPT_RSIZE	"rsize"		/* Max NFS read size (bytes) */
#define	MNTOPT_WSIZE	"wsize"		/* Max NFS write size (bytes) */
#define	MNTOPT_TIMEO	"timeo"		/* NFS timeout (1/10 sec) */
#define	MNTOPT_RETRANS	"retrans"	/* Max retransmissions (soft mnts) */
#define	MNTOPT_ACTIMEO	"actimeo"	/* Attr cache timeout (sec) */
#define	MNTOPT_ACREGMIN	"acregmin"	/* Min attr cache timeout (files) */
#define	MNTOPT_ACREGMAX	"acregmax"	/* Max attr cache timeout (files) */
#define	MNTOPT_ACDIRMIN	"acdirmin"	/* Min attr cache timeout (dirs) */
#define	MNTOPT_ACDIRMAX	"acdirmax"	/* Max attr cache timeout (dirs) */
#define	MNTOPT_NOAC	"noac"		/* Don't cache attributes at all */
#define	MNTOPT_NOCTO	"nocto"		/* No close-to-open consistency */
#define	MNTOPT_BG	"bg"		/* Do mount retries in background */
#define	MNTOPT_FG	"fg"		/* Do mount retries in foreground */
#define	MNTOPT_RETRY	"retry"		/* Number of mount retries */
#define	MNTOPT_DEV	"dev"		/* Device id of mounted fs */
#define	MNTOPT_POSIX	"posix"		/* Get static pathconf for mount */
#define	MNTOPT_MAP	"map"		/* Automount map */
#define	MNTOPT_DIRECT	"direct"	/* Automount   direct map mount */
#define	MNTOPT_INDIRECT	"indirect"	/* Automount indirect map mount */
#define	MNTOPT_LLOCK	"llock"		/* Local locking (no lock manager) */
#define	MNTOPT_IGNORE	"ignore"	/* Ignore this entry */
#define	MNTOPT_VERS	"vers"		/* protocol version number indicator */
#define	MNTOPT_PROTO	"proto"		/* protocol network_id indicator */
#define	MNTOPT_SEC	"sec"		/* Security flavor indicator */
#define	MNTOPT_SYNCDIR	"syncdir"	/* Synchronous local directory ops */
#define	MNTOPT_NOSETSEC	"nosec"		/* Do no allow setting sec attrs */
#define	MNTOPT_NOPRINT	"noprint"	/* Do not print messages */
#define	MNTOPT_LARGEFILES "largefiles"	/* allow large files */
#define	MNTOPT_NOLARGEFILES "nolargefiles" /* don't allow large files */
#define	MNTOPT_FORCEDIRECTIO "forcedirectio" /* Force DirectIO on all files */
#define	MNTOPT_NOFORCEDIRECTIO "noforcedirectio" /* No Force DirectIO */
#define	MNTOPT_DISABLEDIRECTIO "disabledirectio" /* Disable DirectIO ioctls */
#define	MNTOPT_PUBLIC	"public"	/* Use NFS public file handlee */
#define	MNTOPT_LOGGING "logging" 	/* enable logging */
#define	MNTOPT_NOLOGGING "nologging" 	/* disable logging */
#define	MNTOPT_ATIME	"atime"		/* update atime for files */
#define	MNTOPT_NOATIME  "noatime"	/* do not update atime for files */
#define	MNTOPT_GLOBAL	"global"	/* Cluster-wide global mount */
#define	MNTOPT_NOGLOBAL	"noglobal"	/* Mount local to single node */
#define	MNTOPT_DFRATIME	"dfratime"	/* Deferred access time updates */
#define	MNTOPT_NODFRATIME "nodfratime"	/* No Deferred access time updates */
#define	MNTOPT_NBMAND	"nbmand"	/* allow non-blocking mandatory locks */
#define	MNTOPT_NONBMAND	"nonbmand"	/* deny non-blocking mandatory locks */
#define	MNTOPT_XATTR	"xattr"		/* enable extended attributes */
#define	MNTOPT_NOXATTR	"noxattr"	/* disable extended attributes */
#define	MNTOPT_EXEC	"exec"		/* enable executables */
#define	MNTOPT_NOEXEC	"noexec"	/* disable executables */
#define	MNTOPT_RESTRICT	"restrict"	/* restricted autofs mount */
#define	MNTOPT_BROWSE	"browse"	/* browsable autofs mount */
#define	MNTOPT_NOBROWSE	"nobrowse"	/* non-browsable autofs mount */
#endif /* SPL_MNTENT_H */
