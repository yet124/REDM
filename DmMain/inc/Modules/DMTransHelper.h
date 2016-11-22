// ----------------------------------------------------------------
// Copyright (c)  
// All rights reserved.
// 
// File name:	DMTransHelper.h
// File mark:   
// File summary:
// Author:		guoyouhuang
// Edition:     1.0
// Create date: 2016-11-21
// ----------------------------------------------------------------
#pragma once

namespace DM
{
#define  DMLAG_ROOT                         L"dmlg"
#define  DMLAG_NAME                         L"name"
#define  DMLAG_NODE                         L"node"
#define  DMLAG_ITEM                         L"item"
#define  DMLAG_SRC                          L"src"
#define  DMLAG_TRANS                        L"trans"


	/// <summary>
	///		内置语言包的Node节点
	/// </summary>
	class DMTransNode : public DMMapT<CStringW,CStringW>
	{
	public:
		DMTransNode(CStringW strName);
	public:
		CStringW        m_strNodeName;			
	};
	typedef DMTransNode* DMTransNodePtr;


	/// <summary>
	///		内置某个语言包
	/// </summary>
	class DMLanguageItem : public DMArrayT<DMTransNodePtr>
	{
	public:
		DMLanguageItem(CStringW strName);
		virtual~DMLanguageItem();

	public:// 辅助
		DMTransNodePtr FindTransNodePtr(CStringW strNodeName);

	public:
		virtual void PreArrayObjRemove(const DMTransNodePtr &obj);
		virtual bool EqualArrayObj(const DMTransNodePtr &objsrc, const DMTransNodePtr &objdest);

	public:
		CStringW        m_strLanguageName;			
	};
	typedef DMLanguageItem* DMLanguageItemPtr;

}//namespace DM