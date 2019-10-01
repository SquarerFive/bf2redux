// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class reduxprojectEditorTarget : TargetRules
{
	public reduxprojectEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		ExtraModuleNames.Add("reduxproject");

        bCompileChaos = true;
        bUseChaos = false;
        bCompilePhysX = true;
        bCompileAPEX = true;
        bCompileNvCloth = true;
        bCustomSceneQueryStructure = true;
        BuildEnvironment = TargetBuildEnvironment.Unique;
    }
}
