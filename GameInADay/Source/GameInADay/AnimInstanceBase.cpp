// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstanceBase.h"

void UAnimInstanceBase::UpdateAnimationProperties()
{
	
}

void UAnimInstanceBase::Crouched()
{
	IsCrouching = true;
}

void UAnimInstanceBase::UnCrouched()
{
	IsCrouching = false;
}