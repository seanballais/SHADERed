#pragma once
#include "UIView.h"
#include "../ImGUI/TextEditor.h"
#include "../Objects/PipelineItem.h"
#include <d3d11.h>
#include <deque>

namespace ed
{
	class CodeEditorUI : public UIView
	{
	public:
		CodeEditorUI(GUIManager* ui, ed::InterfaceManager* objects, const std::string& name = "", bool visible = false) : UIView(ui, objects, name, visible), m_selectedItem(-1) {
			m_consolas = ImGui::GetIO().Fonts->AddFontFromFileTTF("consola.ttf", 15.0f);
		}

		virtual void OnEvent(const ml::Event& e);
		virtual void Update(float delta);

		void OpenVS(PipelineItem item);
		void OpenPS(PipelineItem item);

		std::vector<std::pair<std::string, bool>> GetOpenedFiles();

	private:
		class StatsPage
		{
		public:
			StatsPage() : IsActive(false), Info(nullptr) {}
			~StatsPage()
			{
				
			}
			bool IsActive;

			void* Info;
		};

	private:
		void m_open(PipelineItem item, bool vs);

		// font for code editor
		ImFont *m_consolas;

		// menu bar item actions
		void m_save(int id);
		void m_compile(int id);
		void m_fetchStats(int id);
		void m_renderStats(int id);

		std::vector<PipelineItem> m_items;
		std::vector<TextEditor> m_editor;
		std::vector<StatsPage> m_stats;
		std::vector<bool> m_isVertexShader;
		std::deque<bool> m_editorOpen;

		int m_selectedItem;
	};
}