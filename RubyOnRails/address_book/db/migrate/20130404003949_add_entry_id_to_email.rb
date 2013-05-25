class AddEntryIdToEmail < ActiveRecord::Migration
  def change
    add_column :emails, :entry_id, :integer
  end
end
