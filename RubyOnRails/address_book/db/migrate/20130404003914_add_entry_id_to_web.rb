class AddEntryIdToWeb < ActiveRecord::Migration
  def change
    add_column :webs, :entry_id, :integer
  end
end
