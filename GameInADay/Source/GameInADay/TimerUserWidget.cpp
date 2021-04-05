// Fill out your copyright notice in the Description page of Project Settings.


#include "TimerUserWidget.h"


void UTimerUserWidget::GetTimer(int timerIn)
{
	Minutes = timerIn / 60;
	timerIn = timerIn % 60;
	Seconds = timerIn;
	TimeDisplay = FString::FromInt(Minutes)+":"+FString::FromInt(Seconds);
	
}
